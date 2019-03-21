# Antroji-Uzduotis
OOP antroji užduotis. Programoje gali būti apdorojami studentų duomenys: vardas, pavardė, namų darbai, egzaminai. Pagrindinė funkcija - apskaičiuoti studentų galutinius rezultatus pagal vidurkio formulę.

Užduoties aprašas: https://github.com/objprog/paskaitos2019/wiki/2-oji-u%C5%BEduotis

# Kaip paleisti programą?
Pasirinktoje IDE sukūrus naują konsolės programą isikelti į projektą parsisiųstus *.h* bei *.cpp* failus ir juos sukompiliuoti. Įvedimo failą galite patys sugeneruoti arba susikurti. *kursiokai.txt* yra pavyzdinis failas. *Second_Task.cpp* yra pagrindinis (main) failas.

# Changelog
### [v1.0.1a](https://github.com/abelzis/Antroji-Uzduotis/releases/tag/v1.0.1a) (2019-03-22)
**Pridėta**
  - CMake failas
  
**Koreguota**
  - Geriausių-blogiausių studentų išskyrimas dabar greitesnis ir naudoja mažiau atminties visais atvejais (ypač `std::vector` ir `std::deque`).
  - Kodo aiškumas: UI (User Interface) perkeltas į atskirą failą; UI funkcijos atskirtos; Nereikalingų eilučių pašalinimas; Nereikalingų preprocesoriaus direktyvų pašalinimas;

### [v1.0](https://github.com/abelzis/Antroji-Uzduotis/releases/tag/v1.0) (2019-03-17)
**Pridėta**
  - Integruota galimybė `functions.h` faile pasirinkt norimą konteinerį 
  
  ![Header](https://i.gyazo.com/5a7da138aa69a8d22389d4b75ce531b6.png)
  
  - Galimybė rūšiuoti blogesnius studentus rūšiuoti nauju būdu (perkeliant blogai besimokančius studentus iš konteinerio į kitą, o gerus palikti pirmajame konteineryje) ("best-worst2")
  - Galimybė atlaisvinti atmintį ("del-stud")

**Koreguota**
  - Pagerintas atsitiktinių skaičių generatorius (tik nuo C++11)
  - Sumažintas programos atminties naudojimas
  - Paspartintas programos veikimas
  
____________________________________________________________________________
   **Papildoma informacija bei pastebėjimai** **(papildyta: 2019-03-17)**
   
   Pagaliau, iš esmės, baigta programa. Nėra tobula, tačiau kriterijus atitinkanti, neblogai veikianti programa (didžiausia likusi klaida yra ta, kad kartais programa negali suskaičiuoti viso laiko). Tačiau laikas įvertinti galutinius pokyčius. Šioje versijoje pridėtas naujas geriausiųjų ir blogiausiųjų studentų atrinkimo būdas: blogiausius studentus iš pagrindinio konteinerio perkelt į naują, o gerus studentus palikt senajame. Taip sutaupoma atminties. Tačiau šis būdas yra optimalus tik `std::list` tipo konteineriams, nes juose naudojamos rodyklės į sekantį ir praeitą saugomą elementą. Vektoriam ir dekam - skausminga, nes pašalinus elementą, reikia iš naujo perskirstyti atmintį.
   
   Atrodo, kad taip yra sutaupoma atmintis, tačiau nė velnio. `std::list` naudoja daugiau nei 2 kartus daugiau atminties, nei `std::vector`. O reikalinga atmintis naujiems geriausiųjų ir blogiausiųjų studentų konteineriams sukurti reikalauja nedidelės dalies visos užimamos atminties (tik vardui, pavardei ir rezultatui saugoti). Plius `std::vector` veikia greičiausiai iš visų.
   
   Net nelabai buvo prasmės atlikti laiko matavimus. Naują metodą gali įveikti tik `std::list`, nes tik jam ir buvo jis sukurtas (milijoną studentų apdoroja per ~17sec.), o `std::vecto` ir `std::deque` tuos pačius duomenis apdorotų per kelias valandas (nematavau, labai ilgai...).
   
   Šiam kartui tiek.
   
____________________________________________________________________________

### [v0.5](https://github.com/abelzis/Antroji-Uzduotis/releases/tag/v0.5) (2019-03-01)
**Koreguota**
  - Sukurti du atskiri *branches*. Abiejuose atlikti konteinerių pakitimai: viename `std::vector` pakeistas į `std::list`, o kitame `std::vector` pakeistas į `std::deque`.
  
____________________________________________________________________________
   **Papildoma informacija bei pastebėjimai** **(papildyta: 2019-03-01)**
   
   Prieita dar viena versija, kurioje tikslas išbandyti įvairius C++ siūlomus konteinerius ir palyginti jų efektyvumą šios programos atveju. Bus naudojami šie konteineriai: `std::vector`, `std::list`, `std::deque`.
   
   Yra žinoma bazinė informacija apie konteinerių struktūrą: `std::vector` yra eilė/masyvas elementų vienoje tiesėje, `std::list` yra dvipusis sąrašas, sujungtas rodyklėmis, `std::deque` yra sąrašas eilių/masyvų, sujungtų rodyklėmis. Programa neatlieka jokių elementų iterpimų į konteinerio vidurį ar šalinimų iš jo vidurio. Vadinasi, **Hipotezė**: `std::vector` ir `std::deque` turėtų užimti panašiai laiko (`std::vector` šiek tiek greitesnis), netoli, bet ne per daugiausiai atsilikti turėtų `std::list`.
   
   Atlikau laiko matavimus *Release mode*, `/02` optimization aplinkoje su milijonu (1,000,000) atsitiktinai sugeneruotų objektų (visą laiką naudojau tą patį failą). Rezultatai buvo išvesti į skirtingus failus (patikrinau, kad rezultatai sutaptų).
   
   **Rezultatai**:
   
   ![Time containers](https://i.gyazo.com/217f406581289aa7886c81b96754aa8d.png)
   
   Lentelėje pateikiau rezultatus laiko trukmės skirtingiems konteinerių tipams. Geltonam fone pažymėti atitinkami vidutiniai laikai. Aiškus lyderis - `std::vector`, nuo kurio ne per daugiausiai atsilieka `std::deque` (tikėjausi truputį mažiau atsiliks), ir paskutinioj vietoj, *ženkliai* prasčiau pasirodė `std::list`. Nelabai suprantu kodėl, nes testo metu nuskaitymą iš failo atliko greitai, taip pat apdorojimą atliko kaip `std::deque`, tačiau išrašinėjo į failą vėžlio greičiu. Tai nesuvokiu kokia priežastis to, nes funkcijų iš esmės nekeičiau...
   
   ![Time containers graph](https://i.gyazo.com/23fa3c9a583bc13a6bdb90cbcab5a4f2.png)
   
   **Išvados**: `std::vector` 95% atvejų yra geriausias konteineris. Taškas.
   
____________________________________________________________________________

# Changelog
### [v0.4](https://github.com/abelzis/Antroji-Uzduotis/releases/tag/v0.4) (2019-02-28)
**Pridėta**
  - Dabar yra galimybė atidaryti betkokį tekstinį *.txt* failą programos aplankale.
  - Galimybė generuoti atsitiktinius šabloninių vardų bei pavardžių studentų objektus su atsitiktiniais pažymiais (pažymių kiekis - nuo 0 iki 50).
  - Pridėta komanda skaičiuojanti galutinius vidurkius.
  - Pridėta komanda skaičiuojanti galutinias medianas.
  - Pridėta funkcija skirstanti studentus į *geresnius* (jei **galutinis vidurkis >= 5**) ir *blogesnius* (jei **galutinis vidurkis < 5**).
  - Pridėta funkcija išrašanti į atskirus failus *geresnius* bei *blogesnius* studentus.

**Koreguota**
  - Programos veikimo matavimo laikas dabar yra tikslesnis (nanosekundžių tikslumu).
  - Koreguotos bei papildytos instrukcijos.
  - `C-array` nebepalaikomas. Kitoje programos versijoje jo nebeliks.
  - Jei yra tik vienas pažymys, vadinasi, tai egzamino pažymys ir vidurkis bei mediana bus lygūs egzamino įvertinimui.
  
____________________________________________________________________________
 **Papildoma informacija bei pastebėjimai** **(papildyta: 2019-02-28)**
 
 Ketvirtoji programos versija privertė stebėti programos naudingą veikimo laiką, ypač kai buvo pridėtos failų generavimo bei geriausiųjų ir blogiausiųjų išvedimo į failus funkcijos. Teko matuoti laiką, kurį programa užtruko generuodama `10`, `100`, `1000`, `10000` bei `100000` objektų dydžių failus ir atliekant šiu objektų nuskaitymą, skaičiavimą bei išvedimą. 
 
 Kiekvienam objektų kiekiui buvo atlikti laiko matavimai **10 kartų**, kiekvieną kartą iš naujo generuojant failą. Studento **įvertinimų kiekis gali svyruoti nuo 0 iki 50**. Programos parametrai: *Release mode*, `/02` optimization. **Hipotezė**: kadangi duomenų kiekis kiekvieną kartą didėja 10 kartų, programos veikimo laikas turėtų taip pat didėti 10 kartų. **Rezultatai**:
 
 ![Timing](https://i.gyazo.com/f12a641d1d6488ada4e252c34bc6e495.png)
 
 Šioje lentelėje mėlyna spalva pažymėti langeliai rodo stulpelius su programos veikimo laiko matavimais sekundėmis. Geltona spalva - vidutiniai rezultatų išvesti laikai.
 
  Palyginus santykinius laikų pokyčius tarp kiekvieno objektų dydžio pokyčio, gaunasi ne visai tai, ko tikėtasi - santykiniai laiko skirtumai pirmose iteracijose nesiekia net 5 kartų. Ir tik paskutinės iteracijos su didesniais duomenų kiekiais laikas skiriasi jau beveik 10 kartų. Pavaizdavau grafiku rezultatus:
  
 ![Time Graph](https://i.gyazo.com/d819c334442b39cc71beb228c93c2683.png)
 
 Grafike matosi, kad 100 duomenų kiekis, kuris yra 10 kartų didesnis nei 10 duomenų kiekis, nors laikas pailgėjo tik 2 kartus - iš 0.0032sec iki 0.0062sec. Tik didesniuose duomenų kiekiuose laiko trukmių santykiai artėja duomenų kiekių santykiui.
 
 **Išvados**: labai mažus kiekius duomenų mažiau apsimoka skaičiuoti, nei šiek tiek didesnius. Taip pat - laiko matavimo testas yra prastas, nes *60%* laiko sudarė atsitiktinio failo generavimas, *35%* laiko sudarė geriausiųjų ir blogiausiųjų išvedimas į atskirus failus, o like *5%* - duomenų nuskaitymas bei skaičiavimai. Vadinasi, **95%** laiko priklausė nuo rand() funkcijos, ir tik **5%** nuo pačio algoritmo.
 
____________________________________________________________________________

### [v0.3](https://github.com/abelzis/Antroji-Uzduotis/releases/tag/v0.3) (2019-02-19)
**Koreguota**
  - Sumažinta tikimybė užlūžti programai priėmus neteisingus duomenis.
  - Sumažinta tikimybė neteisingai interpretuoti duomenis.
  - Papildytas *kuriokai.txt* tekstinio failo šablonas.
  - Papildytos vidurkio bei medianos skaičiavimo formulės. Jei neatliktas joks namų darbas, pažymys bus sudarytas tik iš egzamino svorio padauginto iš egzamino rezultato. Jei nėra net ir egzaminų, išvedami nuliai. Jei duomenų perskaityt ir interpretuot neįmanoma - išvedami nuliai.
  - Papildytas ir pakoreguotas **README** failas.

### [v0.2.4](https://github.com/abelzis/Antroji-Uzduotis/releases/tag/v0.2.4) (2019-02-18)
**Koreguota**
  - C-type masyvas dabar naudoja mažiau atminties nei prieš tai.
  
____________________________________________________________________________
 **Papildoma informacija bei pastebėjimai** **(papildyta: 2019-02-21)**
 
 Dar vienas smagus pastebėjimas iš gerbiamo dėstytojo - debug mode yra daug lėtas, todėl patarė naudoti release mode. Ir iš tiesų - programa veikia gerokai efektyviau. Sparta dar kartą padidėjo apie 10 kartų tiek `vector` tipo konteineriui ![Vector release time](https://i.gyazo.com/c17e313d4a28426427f77c1e084360b9.png), tiek `C-array` tipo konteineriui ![C-array release time](https://i.gyazo.com/95d778e22c036e5d5c45f1c4962a6048.png). Matome iš šių paveiksliukų, kad `vector` tipas jau panašus ir beveik toks pat greitas kaip `C-array` tipas (galima paklaida). Studentų kiekis - *207900*.
 
 Kas dar nustebino, kad atminties kiekis *gerokai* sumažėjo. `vector` objektas naudojo vos tik 30Mb atminties (debug metu net 112Mb!) ![Vector release memory](https://i.gyazo.com/7356a1a6fc9a23449a88cd0f502b7af3.png), o `C-array` objektas naudojo 57Mb atminties (debug metu net 132Mb) ![C-array release memory](https://i.gyazo.com/b1961be4ede59221889a25e63d9cea36.png).
 
 **Pamoka išmokta - matuojant laika, atmintį ir panašius rezultatus, naudoti būtinai release mode, o ne debug.**
 
 **(papildyta: 2019-02-20)**
 
 Dėstytojas pasiūlė įdėja panaudoti optimizavimo vėliavėles, nes galbūt `vector` tipo konteineris nenaudoja greičiausių savo savybių, ir dar kartą patikrinti testavimą bei gautus rezultatus. Panaudojus optimizavimo vėliavėlę /O2, programos sparta padidėjo apie 10 kartų. Todėl testavimui padidinau studentų kiekį iki *207900*.
 ![Student Size](https://i.gyazo.com/9dbca8fbbccc7e23d3e3e40f8b64780b.png)
 
 `vector` tipas nuskaitus duomenis ir juos apdorojus užtruko apie 3.2 sekundes: ![Vector time](https://i.gyazo.com/05beef13be91f055efbc53496558045f.png) ir naudoja apie 112Mb atminties: ![Vector memory](https://i.gyazo.com/3f19eb53daf3d53ea447c5ffa41f3e3d.png).
 
 Tuo tarpu `C-array` tą patį darba atliko vėl per gerokai trumpesnį laiką: 1.8 sekundės ![C-array time](https://i.gyazo.com/1c308a476953f6dfadf6bef917dd6dca.png), o naudoja truputį daugiau atminties - apie 132Mb ![C-array memory](https://i.gyazo.com/c3fff74d5d208039504743c9caa8a6b1.png)
 
 Juokinga, nes `vector` yra stipriai optimizuotas profesionalių programuotojų ir turėtų teoriškai dirbti beveik tokiu pat greičiu kaip `C-array` su visais savo privalumais, tačiau taip nėra.
 
 ***`vector` ir `C-array` funkcijos yra ekvivalenčios. Pirma kurtas `vector`, tada perkopijuotas ir pakoreguotas atitinkamai į `C-array`.***
  
 **(papildyta: 2019-02-19)**
 
 Atlikus nedidelį testą - leisti programai nuskaityti *7000* studentų su namų darbais bei egzaminais iš failo ir palyginti laiko bei atminties efektyvumą tarp `std::vector` bei `C-type array` konteinerių, akivaizdžiai matosi efektyvumo skirtumas tarp šių realizacijų. Tradicinis masyvas veikia maždaug 2 kartus greičiau, negu modernus `vector` tipo konteineris. Tai greičiausiai todėl, kad `vector` yra dalinai automatizuotas, siekiant sutaupyti atminties. Būtent todėl buvo matomas nemažas skirtumas: duomenims saugoti `vector` konteinery prireikė apie 4,2Mb atminties, kol tuo tarpu, C masyve - beveik 8Mb atminties. Tai leido suprasti, kuo skirtingi tipai skiriasi ne tik struktūra, bet ir efektyvumu.
 
 Galvojau, kaip galima optimizuot C tipo masyvą, nes `vector` sugebėjo. Prisiminiau, kad namų darbų vertės yra nuo 1 iki 10. Tai koks tikslas 5bitų skaičių saugoti 32bitų kintamajame (`int`)? Pakeisdamas tipą `int` į `unsigned char` namų darbų vertės yra saugomos tik 8bitų kintamuosiuose. Atlikus iš naujo, tą patį *7000* studentų įvedimo ir apdorojimo testą, atminties panaudojimas sumažėjo vos iki 5.1Mb, o sparta liko ta pati. Todėl sugebėjau sukurti 2 kartus greitesnį modulį, ir tik ~1.25 kartus užimantį daugiau atminties. Neblogas sandoris.
 
____________________________________________________________________________

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
