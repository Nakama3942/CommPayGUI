<!--
[![template](https://img.shields.io/badge/Repository-template-darkred)](https://github.com/Nakama3942/template_rep)
[![GitHub license](https://img.shields.io/github/license/Nakama3942/template_rep?color=darkorange&style=flat-square)](https://github.com/Nakama3942/template_rep/blob/main/LICENSE)
-->

### Замечание
Это дальнейшее развитие моего проекта CommPay. Я создал графическую оболочку для моего приложения и под неё адаптировал старый код.

# CommPayGUI
## Overview
CommPay (полн. "Communal Payment", рус. - "Коммунальный платёж") - программа _с графическим интерфейсом_, которая, исходя из названия, будет считать Вам сумму к оплате коммунальных платежей. Эта программа учитывает все коэфициенты, которые высчитываются коммунальными службами. Если нужно - Вы всегда сможете изменить, как тариф (если он изменился), так и сам коэфициент (если он в Вашем регионе отличается).

## Usage
### Расчёт комунальных платежей
![Screenshot_0](https://user-images.githubusercontent.com/73797846/109571784-db03cb80-7af4-11eb-9fc0-bcf0a382b020.png)
### Изменение тарифов
![Screenshot_1](https://user-images.githubusercontent.com/73797846/109571785-db9c6200-7af4-11eb-9aaf-a5895aa4e0ac.png)
### Изменение валюты пользователя
![Screenshot_2](https://user-images.githubusercontent.com/73797846/109571788-dc34f880-7af4-11eb-9d2f-7fb7f4712082.png)
### Сохранение истории расчётов
![Screenshot_3](https://user-images.githubusercontent.com/73797846/109571790-dc34f880-7af4-11eb-8290-ad179a9a678e.png)
### Поддержка русского, украинского и английского языков
![Screenshot_5](https://user-images.githubusercontent.com/73797846/109571791-dc34f880-7af4-11eb-861a-130a58df84cc.png)
### Поддержка светлой и тёмной темы BreezeStyleSheets
![Screenshot_6](https://user-images.githubusercontent.com/73797846/109571792-dccd8f00-7af4-11eb-9899-28b432cf7b6a.png)
![Screenshot_7](https://user-images.githubusercontent.com/73797846/109571793-dccd8f00-7af4-11eb-9a00-7bddb1869b52.png)

## Building
Графический интерфес был написан с использованием библиотек Qt, поэтому и собирать проект нужно в среде разработки Qt. Клонируете репозиторий себе на диск и в среде разрабортки Qt Creator выбираете папку с проектом в окне "открыть". Дальше создаём отдельный репозиторий для скомпилированной программы и в него копируем Config.ini, History.txt, LICENSE.TXT, NOTICE.TXT, а также в директориях с находим необходимые динамические библиотеки: libgcc_s_seh-1.dll, libstdc++-6.dll, libwinpthread-1.dll, Qt6Core.dll, Qt6Gui.dll, Qt6Svg.dll и Qt6Widgets.dll (их в этом репозитории нет). Также из папки с компилятором достаём папку Plugins, в которой должны находиться папки: imageformats, platforms, styles. Дальше в среде разработки компилируем файлы переводов и помещаем готовые .qm-файлы в папку languages нашего проекта, где будет исходник. Рядом с папками plugins и languages разархивируем архив BreezeStyleSheets.zip и помещаем разархивированную директорию со всем её содежимым. Папка готовой программы готова. Осталась сама программа: заходим в проект и компилируем выпуск, заходим в папку, куда скомпилировалась программа и копируем оттуда ЕХЕшник в папку, куда мы поместили все файлы нашей программы. Всё - программа собрана.

## Windows и Linux
Пока программа написана только под Windows, но в следующем обновлении я также адаптирую программу и под Linux.

<!--
## CHANGELOG
- [CHANGELOG](https://github.com/Nakama3942/template_rep/blob/main/CHANGELOG.md)

## CONTRIBUTING
- [CONTRIBUTING](https://github.com/Nakama3942/template_rep/blob/main/CONTRIBUTING.md)

## CODE_OF_CONDUCT
- [CODE_OF_CONDUCT](https://github.com/Nakama3942/template_rep/blob/main/CODE_OF_CONDUCT.md)

## PULL_REQUEST_TEMPLATE
- [PULL_REQUEST_TEMPLATE](https://github.com/Nakama3942/template_rep/blob/main/.github/PULL_REQUEST_TEMPLATE.md)
-->

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
