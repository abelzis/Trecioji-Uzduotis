# Antroji-Uzduotis
OOP antroji užduotis. Programa įvestus studentų duomenis apdoroja ir išveda galutinius įvertinimus.

# Kaip paleisti programą?
Pasirinktoje IDE sukūrus naują konsolės programą isikelti parsisiųstus *.h* bei *.cpp* failus ir juos sukompiliuoti. *kursiokai.txt* failas turėtų būtų programos aplanke. *Second_Task.cpp* yra pagrindinis (main) failas.

# Changelog
### [v0.3](https://github.com/abelzis/Antroji-Uzduotis/releases/tag/v0.3) (2019-02-19)
**Koreguota**
  - Sumažinta tikimybė užlūžti programai priėmus neteisingus duomenis.
  - Sumažinta tikimybė neteisingai interpretuoti duomenis.
  - Papildytas *kuriokai.txt* tekstinio failo šablonas.
  - Vidurkio bei medianos skaičiavimo formulės dabar veda 
  - Papildytos vidurkio bei medianos skaičiavimo formulės. Jei neatliktas joks namų darbas, pažymys bus sudarytas tik iš egzamino svorio padauginto iš egzamino rezultato. Jei nėra net ir egzaminų, išvedami nuliai. Jei duomenų perskaityt ir interpretuot neįmanoma - išvedami nuliai.
  - Papildytas ir pakoreguotas **README** failas.

### [v0.2.4](https://github.com/abelzis/Antroji-Uzduotis/releases/tag/v0.2.4) (2019-02-18)
**Koreguota**
  - C-type masyvas dabar naudoja mažiau atminties nei prieš tai.
  
 **Papildoma informacija bei pastebėjimai** (papildyta: 2019-02-20)
 
 Dėstytojas pasiūlė įdėja panaudoti optimizavimo vėliavėles, nes galbūt `vector` tipo konteineris nenaudoja greičiausių savo savybių, ir dar kartą patikrinti testavimą bei gautus rezultatus. Panaudojus optimizavimo vėliavėlę /O2, programos sparta padidėjo apie 10 kartų. Todėl testavimui padidinau studentų kiekį iki *207900*.
 ![Student Size](https://i.gyazo.com/9dbca8fbbccc7e23d3e3e40f8b64780b.png)
 
 `vector` tipas nuskaitus duomenis ir juos apdorojus užtruko apie 3.2 sekundes: ![Vector time](https://i.gyazo.com/05beef13be91f055efbc53496558045f.png) ir naudoja apie 112Mb atminties: ![Vector memory](https://i.gyazo.com/3f19eb53daf3d53ea447c5ffa41f3e3d.png).
 
 Tuo tarpu `C-array` tą patį darba atliko vėl per gerokai trumpesnį laiką: 1.8 sekundės ![C-array time](https://i.gyazo.com/1c308a476953f6dfadf6bef917dd6dca.png), o naudoja truputį daugiau atminties - apie 132Mb ![C-array memory](https://i.gyazo.com/c3fff74d5d208039504743c9caa8a6b1.png)
 
 Juokinga, nes `vector` yra stipriai optimizuotas profesionalių programuotojų ir turėtų teoriškai dirbti beveik tokiu pat greičiu kaip `C-array` su visais savo privalumais, tačiau taip nėra.
 
 ***`vector` ir `C-array` funkcijos yra ekvivalenčios. Pirma kurtas `vector`, tada perkopijuotas ir pakoreguotas atitinkamai į `C-array`.***
  
 (papildyta: 2019-02-19)
 
 Atlikus nedidelį testą - leisti programai nuskaityti *7000* studentų su namų darbais bei egzaminais iš failo ir palyginti laiko bei atminties efektyvumą tarp `std::vector` bei `C-type array` konteinerių, akivaizdžiai matosi efektyvumo skirtumas tarp šių realizacijų. Tradicinis masyvas veikia maždaug 2 kartus greičiau, negu modernus `vector` tipo konteineris. Tai greičiausiai todėl, kad `vector` yra dalinai automatizuotas, siekiant sutaupyti atminties. Būtent todėl buvo matomas nemažas skirtumas: duomenims saugoti `vector` konteinery prireikė apie 4,2Mb atminties, kol tuo tarpu, C masyve - beveik 8Mb atminties. Tai leido suprasti, kuo skirtingi tipai skiriasi ne tik struktūra, bet ir efektyvumu.
 
 Galvojau, kaip galima optimizuot C tipo masyvą, nes `vector` sugebėjo. Prisiminiau, kad namų darbų vertės yra nuo 1 iki 10. Tai koks tikslas 5bitų skaičių saugoti 32bitų kintamajame (`int`)? Pakeisdamas tipą `int` į `unsigned char` namų darbų vertės yra saugomos tik 8bitų kintamuosiuose. Atlikus iš naujo, tą patį *7000* studentų įvedimo ir apdorojimo testą, atminties panaudojimas sumažėjo vos iki 5.1Mb, o sparta liko ta pati. Todėl sugebėjau sukurti 2 kartus greitesnį modulį, ir tik ~1.25 kartus užimantį daugiau atminties. Neblogas sandoris.

### [v0.2.3](https://github.com/abelzis/Antroji-Uzduotis/releases/tag/v0.2.3) (2019-02-17)
**Pridėta**
  - Galimybė saugoti duomenis C-type masyve.
  - Galimybė iš naujo atidaryti *kursiokai.txt* failą.
  - Skaičiuojamas laikas nuskaitant duomenis ir atliekant darbą su duomenimis.

**Koreguota**
  - Pataisyta programos instrukcija.
  - Papildytas **README** failas.

### [v0.2.2](https://github.com/abelzis/Antroji-Uzduotis/releases/tag/v0.2.2) (2019-02-14)
**Koreguota**
  - Pataisytas rezultatų išvedimo formatavimas, atsižvelgiant į vardų bei pavardžių ilgius.
  - Papildytas **README** failas.
  

### [v0.2.1](https://github.com/abelzis/Antroji-Uzduotis/releases/tag/v0.2.1) (2019-02-13)
**Pridėta**
  - Sukurtas **functions.cpp** failas, kuriame aprašytos programoje naudojamos funkcijos.
  - Sukurtas **functions.h** failas, kuriame aprašyta *Student* struktūra bei deklaruotos funkcijos aprašytos **functions.cpp** faile.
  
**Koreguota**
  - Papildytas **README** failas.

### [v0.2](https://github.com/abelzis/Antroji-Uzduotis/releases/tag/v0.2) (2019-02-13)
**Pridėta**
  - Pridėtas pavyzdinis duomenų failas **kursiokai.txt**.
  - Galimybė paimti duomenis iš failo **kursiokai.txt**.
  - Rezultatai surikiuojami pagal vardą.
  
**Koreguota**
  - Vidurkių skaičiavimo funkcijos nebedalina iš 0.
  - Išvedimo struktūroje išvedami vidurkiai išlaiko x.xx struktūrą.
  - Instrukcijos dabar aiškesnės.
  - Papildytas **README** failas.

### [v0.1](https://github.com/abelzis/Antroji-Uzduotis/releases/tag/v0.1) (2019-02-12)
**Pridėta**
  - Galimybė atsitiktinai sugeneruoti namų darbų bei egzaminų rezultatus.

**Koreguota**
  - Instrukcijos dabar aiškesnės.
  - Programa dabar nebeužsidaro iškarto įrašius 'end'.
  - Papildytas **README** failas.


### [v0.1-alpha](https://github.com/abelzis/Antroji-Uzduotis/releases/tag/v0.1-alpha) (pre-release) (2019-02-12)
**Pridėta**
  - Sukurta pradinė programos versija.
  - Galimybė įvesti neribotus studentų, bei namų darbų kiekius.
  - Skaičiuojami galutiniai rezultatai vidurkio bei medianos atžvilgiais.
  - Struktūruotas rezultatų išvedimas.
