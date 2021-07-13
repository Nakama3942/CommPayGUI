[![template](https://img.shields.io/badge/Repository-template-darkred)](https://github.com/Nakama3942/template_rep)
[![GitHub license](https://img.shields.io/github/license/Nakama3942/CommPayGUI?color=darkorange&style=flat-square)](https://github.com/Nakama3942/CommPayGUI/blob/main/LICENSE)

[![CHANGELOG](https://img.shields.io/badge/here-CHANGELOG-yellow)](https://github.com/Nakama3942/CommPayGUI/blob/main/CHANGELOG.md)
[![CONTRIBUTING](https://img.shields.io/badge/here-CONTRIBUTING-indigo)](https://github.com/Nakama3942/CommPayGUI/blob/main/CONTRIBUTING.md)
[![CODE_OF_CONDUCT](https://img.shields.io/badge/here-CODE_OF_CONDUCT-darkgreen)](https://github.com/Nakama3942/CommPayGUI/blob/main/CODE_OF_CONDUCT.md)
[![PULL_REQUEST_TEMPLATE](https://img.shields.io/badge/here-PULL_REQUEST_TEMPLATE-orange)](https://github.com/Nakama3942/CommPayGUI/blob/main/.github/PULL_REQUEST_TEMPLATE.md)

### Comment
This is a further development of my CommPay project. I created a graphical shell for my application and adapted the old code for it.

# CommPayGUI
## Overview
CommPay (full "Communal Payment") is a program _with a graphical interface_, which, based on its name, will calculate the amount to be paid for utility bills. This program takes into account all the coefficients that are calculated by utilities. If necessary, you can always change both the tariff (if it has changed) and the coefficient itself (if it differs in your region).

## Usage
### Calculation of utility bills
![Screenshot_0](https://user-images.githubusercontent.com/73797846/109571784-db03cb80-7af4-11eb-9fc0-bcf0a382b020.png)
### Tariff changes
![Screenshot_1](https://user-images.githubusercontent.com/73797846/109571785-db9c6200-7af4-11eb-9aaf-a5895aa4e0ac.png)
### Changing the user's currency
![Screenshot_2](https://user-images.githubusercontent.com/73797846/109571788-dc34f880-7af4-11eb-9d2f-7fb7f4712082.png)
### Saving the history of calculations
![Screenshot_3](https://user-images.githubusercontent.com/73797846/109571790-dc34f880-7af4-11eb-8290-ad179a9a678e.png)
### Support for Russian, Ukrainian and English languages
![Screenshot_5](https://user-images.githubusercontent.com/73797846/109571791-dc34f880-7af4-11eb-861a-130a58df84cc.png)
### BreezeStyleSheets light and dark theme support
![Screenshot_6](https://user-images.githubusercontent.com/73797846/109571792-dccd8f00-7af4-11eb-9899-28b432cf7b6a.png)
![Screenshot_7](https://user-images.githubusercontent.com/73797846/109571793-dccd8f00-7af4-11eb-9a00-7bddb1869b52.png)

## Building
The graphical interface was written using the Qt libraries, so you need to build the project in the Qt development environment. Clone the repository to your disk and in the Qt Creator development environment select the folder with the project in the "open" window. Next, we create a separate repository for the compiled program and copy Config.ini, History.txt, LICENSE.TXT, NOTICE.TXT into it, and also in the directories with we find the necessary dynamic libraries: libgcc_s_seh-1.dll, libstdc++-6.dll, libwinpthread-1.dll, Qt6Core.dll, Qt6Gui.dll, Qt6Svg.dll and Qt6Widgets.dll (they are not in this repository). Also, from the folder with the compiler, we get the Plugins folder, which should contain the following folders: imageformats, platforms, styles. Next, in the development environment, we compile the translation files and place the finished .qm files into the languages folder of our project, where the source will be. Next to the plugins and languages folders, unzip the BreezeStyleSheets.zip archive and place the unzipped directory with all its contents. The finished program folder is ready. The program itself remains: we go into the project and compile the release, go to the folder where the program was compiled and copy the EXE file from there to the folder where we placed all the files of our program. That's it - the program is assembled.

## Windows & Linux
So far, the program is written only for Windows, but in the next update I will also adapt the program for Linux.

## Authors
<table>
    <tr>
        <td align="center"><a href="https://github.com/Nakama3942"><img src="https://avatars.githubusercontent.com/u/73797846?s=400&u=a9b7688ac521d739825d7003a5bd599aab74cb76&v=4" width="100px;" alt=""/><br /><sub><b>Kalynovsky Valentin</b></sub></a></td>
        <td></td>
    </tr>
    <tr>
        <td></td>
        <td></td>
    </tr>
</table>
