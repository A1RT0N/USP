const express = require('express');
const cors = require('cors');
const chromium = require('chrome-aws-lambda');

const app = express();
app.use(cors()); // Permite CORS para todas as origens

app.get('/scrape', async (req, res) => {
  const input = req.query.input;
  let browser;

  try {
    // Inicializa o Puppeteer usando chrome-aws-lambda (otimizado para Vercel)
    browser = await chromium.puppeteer.launch({
      args: [...chromium.args, '--no-sandbox', '--disable-setuid-sandbox'],
      defaultViewport: chromium.defaultViewport,
      executablePath: await chromium.executablePath,
      headless: true,
    });

    const page = await browser.newPage();

    // Vai para a URL especificada e espera o seletor desejado
    await page.goto(`https://www.cepea.esalq.usp.br/br/indicador/${input}.aspx`, { waitUntil: 'domcontentloaded' });
    await page.waitForSelector("#imagenet-indicador1");

    // Extrai os dados
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

    res.json(dados);

  } catch (error) {
    res.status(500).json({ error: error.message });
  } finally {
    if (browser) await browser.close(); // Fecha o browser ao final, independente do sucesso ou falha
  }
});

// Exporta o app para que a Vercel gerencie a execução
module.exports = app;
