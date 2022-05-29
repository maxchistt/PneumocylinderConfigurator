@echo "Deploying PneumocylinderConfigurator"

:: Путь к папке с деплоером windeployqt.exe
set Qt_DeployerDir=C:\Qt\5.15.0\msvc2019_64\bin
:: Путь к папке этого проекта, %cd% - текущая папка
set PneumocylinderConfigurator_ProjectDir=%cd%\..

cd "%Qt_DeployerDir%"
start windeployqt.exe %PneumocylinderConfigurator_ProjectDir%\x64\Release\PneumocylinderConfigurator.exe