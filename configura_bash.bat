@echo off
echo Configurando Git...

REM Define diretamente o nome de usuário e e-mail
set username=Figor2009
set useremail=igor.antonio.almeida@escola.pr.gov.br

REM Configurações globais do Git
git config --global user.name "%username%"
git config --global user.email "%useremail%"

echo.
echo Configurações aplicadas com sucesso:
git config --global user.name
git config --global user.email

REM that boy pull up in the machine

exit
