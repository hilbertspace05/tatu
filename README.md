# tatu
Extrai imagens de pdf e texto das imagens

Compilado usando MSYS2. As bibliotecas necessárias foram instaladas através do MSYS2. São: tesseract, ghostscript e leptonica.

Para alterar a linguagem de reconhecimento do OCR, é necessário baixar as bibliotecas da linguagem e alterar a linguagem no tesseract.cpp.

A extração de imagens funciona com: ./ghostscript <NOME-DO-PDF> <NOME-BASE-DA-IMAGEM>

Foi utilizado 'g++ -o tesseract tesseract.cpp `pkg-config --libs --cflags tesseract lept` para compilar o tesseract, e 

'g++ -o ghostscript ghostscript.cpp -lgs' para compilar o ghost script.

Para que o programa de OCR funcione sem alterações, é necessário que o nome base da imagem seja 'image'.

É só rodar ./tesseract e colocar a quantidade de páginas que tem o PDF. Para que o tesseract reconheça as linguagens no MSYS2, é necessário que você use o comando 'export TESSDATA_PREFIX=/c/msys64/mingw64/share/tessdata' antes de rodar o programa.
