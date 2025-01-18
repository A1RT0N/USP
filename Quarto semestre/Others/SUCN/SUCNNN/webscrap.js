const puppeteer = require('puppeteer');

exports.handler = async (event) => {
  const input = event.queryStringParameters && event.queryStringParameters.input;
  let browser;

  try {
    browser = await puppeteer.launch({
      headless: "new",
      args: [
        '--no-sandbox',
        '--disable-setuid-sandbox',
        '--disable-dev-shm-usage',
        '--disable-gpu',
        '--single-process',
        '--no-zygote',
      ],
      executablePath: '/opt/render/.cache/puppeteer/chrome/linux-121.0.6167.85/chrome-linux64/chrome'
    });

    const page = await browser.newPage();

    await page.goto(`https://www.cepea.esalq.usp.br/br/indicador/${input}.aspx`, { waitUntil: 'domcontentloaded' });
    await page.waitForSelector("#imagenet-indicador1");

    const dados = await page.evaluate(() => {
      const tabela = document.querySelector("#imagenet-indicador1");
      if (!tabela) {
        return [];
      }
      const linhas = tabela.querySelectorAll("tbody tr");

      const cabecalhos = Array.from(tabela.querySelectorAll("thead th")).map((th) => {
        const texto = th.innerText.trim();
        return texto === "" ? "Data" : texto;
      });
      const dados = [];

      linhas.forEach(tr => {
        const colunas = Array.from(tr.querySelectorAll("td")).map(td => {
          let texto = td.innerText.trim();

          if (/^\d+(\.\d{3})*,\d{2}$/.test(texto)) {
            texto = texto.replace(/\./g, '').replace(',', '.');
          }

          if (texto.includes('%')) {
            texto = texto.replace(',', '.');
          }

          return texto;
        });

        const linhaDados = {};
        cabecalhos.forEach((header, index) => {
          linhaDados[header] = colunas[index] || "DATA";
        });

        dados.push(linhaDados);
      });

      return dados;
    });

    return {
      statusCode: 200,
      body: JSON.stringify(dados),
    };
  } catch (error) {
    return {
      statusCode: 500,
      body: JSON.stringify({ error: error.message }),
    };
  } finally {
    if (browser) await browser.close();
  }
};
