#include <Windows.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

vector <int> zapytania;
string kontynent = "";
string zle="�le!\t\t";

string krajeAF[58]={"Algierii","Angoli","Beninu","Botswany","Burkina Faso","Burundi","Czadu","Demokratycznej Republiki Konga","D�ibuti","Egiptu","Erytrei","Etiopii","Gabonu","Gambii","Ghany","Gwinei","Gwinei Bissau","Gwinei R�wnikowej","Kamerunu","Kenii","Komor�w","Konga","Lesotho","Liberii","Libii", "Madagaskaru", "Majotty", "Malawii", "Mali", "Maroka", "Mauretanii", "Mauritiusu", "Mozambiku", "Namibii", "Nigeru", "Nigerii", "Republiki Po�udniowej Afryki", "Republiki Zielonego Przyl�dka", "Republiki �rodkowoafrykanskiej", "Reunion", "Rwandy", "Sahary Zachodniej", "Senegalu", "Seszeli", "Sierra Leone", "Somalii", "Suazi", "Sudanu", "Sudanu Po�udniowego", "Tanzanii", "Togo", "Tunezji", "Ugandy", "Wybrze�a Ko�ci S�oniowej", "Wyspy �wi�tej Heleny", "Wyspy �wi�tego Tomasza i Ksi���cej", "Zambii", "Zimbabwe"};
string stoliceAF[58]={"Algier","Luanda","Porto-Novo","Gaborone","Wagadugu","Bu�umbura","Nd�amena","Kinszasa","D�ibuti","Kair","Asmara","Addis Abeba","Libreville","Band�ul","Akra","Konakry","Bissau","Malabo","Jaunde","Nairobi","Moroni","Brazzaville","Maseru","Monrovia","Trypolis", "Antananarywa", "Mamoudzou", "Liongwe", "Bamako", "Rabat", "Nawakszut", "Port Louis", "Maputo", "Windhuk", "Niamey", "Abud�a", "Pretoria", "Praia", "Bangi", "Saint-Denis", "Kigali", "Al-Ujun", "Dakar", "Victoria", "Freetown", "Mogadiszu", "Mbabane", "Chartum", "D�uba", "Dodoma", "Lom�", "Tunis", "Kampala", "Jamusukro", "Jamestown", "Sao Tom�", "Lusaka", "Harare"};

string krajeAZ[51]={"Afganistanu","Arabii Saudyjskiej","Armenii","Azerbejd�anu","Bahrajnu","Bangladeszu","Bhutanu","Brunei","Chin","Cypru","Filipin","Gruzji","Hongkongu","Indii","Indonezji","Iraku","Iranu","Izraela","Japonii","Jemenu","Jordanii","Kambod�y","Kataru","Kazachstanu","Kirgistanu","Korei Po�udniowej","Korei P�nocnej","Kuwejtu","Laosu","Libanu","Malediw�w","Malezji","Mjanmy (Birmy)","Mongolii","Nepalu","Omanu","Pakistanu","Palestyny","Singapuru","Sri Lanki","Syrii","Tad�ykistanu","Tajlandii","Tajwanu","Timoru Wschodniego","Turkmenistanu","Uzbekistanu","Wietnamu","Wyspy Bo�ego Narodzenia","Wysp Kokosowych","Zjednoczonych Emirat�w Arabskich"};
string stoliceAZ[51]={"Kabul","Rijad","Erywa�","Baku","Manama","Dhaka","Thimphu","Bandar Seri Begawan","Pekin","Nikozja","Manila","Tbilisi","Hongkong","Nowe Delhi","D�akarta","Bagdad","Teheran","Jerozolima (kwestionowana)","Tokio","Sana","Amman","Phnom Penh","Doha","Astana","Biszkek","Seul","Pjongjang","Kuwejt","Wientian","Bejrut","Male","Kuala Lumpur","Naypyidaw","U�an Bator","Katmandu","Maskat","Islamabad","Ramallah","Singapur","Sri D�ajawardanapura Kotte","Damaszek","Duszanbe","Bangkok","Tajpej","Dili","Aszchabad","Taszkent","Hanoi","Flying Fish Cove","West Island","Abu Zabi"};

string krajeEU[51]={"Albanii","Andory","Austrii","Belgii","Bia�orusi","Bo�ni i Hercegowiny","Bu�garii","Chorwacji","Czarnog�ry","Czech","Danii","Estonii","Finlandii","Francji","Gibraltaru","Grecji","Guernsey","Hiszpanii","Holandii","Irlandii","Islandii","Jersey","Kosowa","Liechtensteinu","Litwy","Luksemburgu","Macedonii (BJRM)","Malty","Monako","Mo�dawii","Niemiec","Norwegii","Polski","Portugalii","Rosji","Rumunii","San Marino","Serbii","Szwajcarii","Szwecji","S�owacji","S�owenii","Turcji","Ukrainy","Watykanu","Wielkiej Brytanii","Wyspy Man","Wysp Owczych","W�gier","W�och","�otwy"};
string stoliceEU[51]={"Tirana","Andora","Wiede�","Bruksela","Mi�sk","Sarajewo","Sofia","Zagrzeb","Podgorica","Praga","Kopenhaga","Tallinn","Helsinki","Pary�","Gibraltar","Ateny","Saint Peter Port","Madryt","Amsterdam","Dublin","Reykjav�k","Saint Helier","Prisztina","Vaduz","Wilno","Luksemburg","Skopje","Valletta","Monako","Kiszyni�w","Berlin","Oslo","Warszawa","Lizbona","Moskwa","Bukareszt","San Marino","Belgrad","Berno","Sztokholm","Bratys�awa","Lublana","Ankara","Kij�w","Watykan","Londyn","Douglas","Thorshavn","Budapeszt","Rzym","Ryga"};

string krajeAM[52]={"Anguilli","Antigui i Barbudy","Argentyny","Aruby","Baham�w","Barbadosa","Belize","Bermud�w","Boliwii","Bonaire","Brazylii","Brytyjskich Wysp Dziewiczych","Chile","Cura�ao","Dominiki","Dominikany","Ekwadoru","Falkland�w","Grenady","Grenlandii","Gujany","Gujany Francuskiej","Gwadelupy","Gwatemali","Haiti","Hondurasu","Jamajki","Kajman�w","Kanady","Kolumbii","Kostaryki","Kuby","Martyniki","Meksyku","Montserratu","Nikaragui","Panamy","Paragwaju","Peru","Portoryko","Saint Kitts i Nevis","Saint Lucii","Saint Vincent i Grenadyny","Saint-Pierre i Miquelon","Salwadoru","Stan�w Zjednoczonych","Surinamu","Trynidadu i Tobago","Turks i Caicos","Urugwaju","Wenezueli","Wysp Dziewiczych Stan�w Zjednoczonych"};
string stoliceAM[52]={"The Valley","Saint John's","Buenos Aires","Oranjestad","Nassau","Bridgetown","Belmopan","Hamilton","Sucre","Kralendijk","Brasilia","Road Town","Santiago","Willemstad","Roseau","Santo Domingo","Quito","Stanley","Saint George's","Nuuk","Georgetown","Kajenna","Basse-Terre","Gwatemala","Port-au-Prince","Tegucigalpa","Kingston","George Town","Ottawa","Bogota","San Jos�","Hawana","Fort-de-France","Meksyk","Plymouth","Managua","Panama","Asunci�n","Lima","San Juan","Basseterre","Castries","Kingstown","Saint-Pierre","San Salvador","Waszyngton, D.C.","Paramaribo","Port-of-Spain","Cockburn Town","Montevideo","Caracas","Charlotte Amalie"};

string krajeAO[24]={"Australii","Fid�i","Guamu","Kiribati","Marian�w P�nocnych","Mikronezji","Nauru","Niue","Norfolk","Nowej Kaledonii","Nowej Zelandii","Palau","Papuy-Nowej Gwinei","Pitcairn","Polinezji Francuskiej","Samoy","Samoa Ameryka�skiego","Tongi","Tuvalu","Vanuatu","Wallis i Futuny","Wysp Cooka","Wysp Marshalla","Wysp Salomona"};
string stoliceAO[24]={"Canberra","Suva","Hag\xe5t\xf1\x61","Tarawa","Capital Hill","Palikir","Yaren","Alofi","Kingston","Numea","Wellington","Ngerulmud","Port Moresby","Adamstown","Papeete","Apia","Fagatogo","Nuku'alofa","Funafuti","Port Vila","Mata Utu","Avarua","Majuro","Honiara"};

string krajeSW[236]={"Algierii","Angoli","Beninu","Botswany","Burkina Faso","Burundi","Czadu","Demokratycznej Republiki Konga","D�ibuti","Egiptu","Erytrei","Etiopii","Gabonu","Gambii","Ghany","Gwinei","Gwinei Bissau","Gwinei R�wnikowej","Kamerunu","Kenii","Komor�w","Konga","Lesotho","Liberii","Libii", "Madagaskaru", "Majotty", "Malawii", "Mali", "Maroka", "Mauretanii", "Mauritiusu", "Mozambiku", "Namibii", "Nigeru", "Nigerii", "Republiki Po�udniowej Afryki", "Republiki Zielonego Przyl�dka", "Republiki �rodkowoafrykanskiej", "Reunion", "Rwandy", "Sahary Zachodniej", "Senegalu", "Seszeli", "Sierra Leone", "Somalii", "Suazi", "Sudanu", "Sudanu Po�udniowego", "Tanzanii", "Togo", "Tunezji", "Ugandy", "Wybrze�a Ko�ci S�oniowej", "Wyspy �wi�tej Heleny", "Wyspy �wi�tego Tomasza i Ksi���cej", "Zambii", "Zimbabwe","Afganistanu","Arabii Saudyjskiej","Armenii","Azerbejd�anu","Bahrajnu","Bangladeszu","Bhutanu","Brunei","Chin","Cypru","Filipin","Gruzji","Hongkongu","Indii","Indonezji","Iraku","Iranu","Izraela","Japonii","Jemenu","Jordanii","Kambod�y","Kataru","Kazachstanu","Kirgistanu","Korei Po�udniowej","Korei P�nocnej","Kuwejtu","Laosu","Libanu","Malediw�w","Malezji","Mjanmy (Birmy)","Mongolii","Nepalu","Omanu","Pakistanu","Palestyny","Singapuru","Sri Lanki","Syrii","Tad�ykistanu","Tajlandii","Tajwanu","Timoru Wschodniego","Turkmenistanu","Uzbekistanu","Wietnamu","Wyspy Bo�ego Narodzenia","Wysp Kokosowych","Zjednoczonych Emirat�w Arabskich","Albanii","Andory","Austrii","Belgii","Bia�orusi","Bo�ni i Hercegowiny","Bu�garii","Chorwacji","Czarnog�ry","Czech","Danii","Estonii","Finlandii","Francji","Gibraltaru","Grecji","Guernsey","Hiszpanii","Holandii","Irlandii","Islandii","Jersey","Kosowa","Liechtensteinu","Litwy","Luksemburgu","Macedonii (BJRM)","Malty","Monako","Mo�dawii","Niemiec","Norwegii","Polski","Portugalii","Rosji","Rumunii","San Marino","Serbii","Szwajcarii","Szwecji","S�owacji","S�owenii","Turcji","Ukrainy","Watykanu","Wielkiej Brytanii","Wyspy Man","Wysp Owczych","W�gier","W�och","�otwy","Anguilli","Antigui i Barbudy","Argentyny","Aruby","Baham�w","Barbadosa","Belize","Bermud�w","Boliwii","Bonaire","Brazylii","Brytyjskich Wysp Dziewiczych","Chile","Cura�ao","Dominiki","Dominikany","Ekwadoru","Falkland�w","Grenady","Grenlandii","Gujany","Gujany Francuskiej","Gwadelupy","Gwatemali","Haiti","Hondurasu","Jamajki","Kajman�w","Kanady","Kolumbii","Kostaryki","Kuby","Martyniki","Meksyku","Montserratu","Nikaragui","Panamy","Paragwaju","Peru","Portoryko","Saint Kitts i Nevis","Saint Lucii","Saint Vincent i Grenadyny","Saint-Pierre i Miquelon","Salwadoru","Stan�w Zjednoczonych","Surinamu","Trynidadu i Tobago","Turks i Caicos","Urugwaju","Wenezueli","Wysp Dziewiczych Stan�w Zjednoczonych","Australii","Fid�i","Guamu","Kiribati","Marian�w P�nocnych","Mikronezji","Nauru","Niue","Norfolk","Nowej Kaledonii","Nowej Zelandii","Palau","Papuy-Nowej Gwinei","Pitcairn","Polinezji Francuskiej","Samoy","Samoa Ameryka�skiego","Tongi","Tuvalu","Vanuatu","Wallis i Futuny","Wysp Cooka","Wysp Marshalla","Wysp Salomona"};

string stoliceSW[236]={"Algier","Luanda","Porto-Novo","Gaborone","Wagadugu","Bu�umbura","Nd�amena","Kinszasa","D�ibuti","Kair","Asmara","Addis Abeba","Libreville","Band�ul","Akra","Konakry","Bissau","Malabo","Jaunde","Nairobi","Moroni","Brazzaville","Maseru","Monrovia","Trypolis", "Antananarywa", "Mamoudzou", "Liongwe", "Bamako", "Rabat", "Nawakszut", "Port Louis", "Maputo", "Windhuk", "Niamey", "Abud�a", "Pretoria", "Praia", "Bangi", "Saint-Denis", "Kigali", "Al-Ujun", "Dakar", "Victoria", "Freetown", "Mogadiszu", "Mbabane", "Chartum", "D�uba", "Dodoma", "Lom�", "Tunis", "Kampala", "Jamusukro", "Jamestown", "Sao Tom�", "Lusaka", "Harare","Kabul","Rijad","Erywa�","Baku","Manama","Dhaka","Thimphu","Bandar Seri Begawan","Pekin","Nikozja","Manila","Tbilisi","Hongkong","Nowe Delhi","D�akarta","Bagdad","Teheran","Jerozolima (kwestionowana)","Tokio","Sana","Amman","Phnom Penh","Doha","Astana","Biszkek","Seul","Pjongjang","Kuwejt","Wientian","Bejrut","Male","Kuala Lumpur","Naypyidaw","U�an Bator","Katmandu","Maskat","Islamabad","Ramallah","Singapur","Sri D�ajawardanapura Kotte","Damaszek","Duszanbe","Bangkok","Tajpej","Dili","Aszchabad","Taszkent","Hanoi","Flying Fish Cove","West Island","Abu Zabi","Tirana","Andora","Wiede�","Bruksela","Mi�sk","Sarajewo","Sofia","Zagrzeb","Podgorica","Praga","Kopenhaga","Tallinn","Helsinki","Pary�","Gibraltar","Ateny","Saint Peter Port","Madryt","Amsterdam","Dublin","Reykjav�k","Saint Helier","Prisztina","Vaduz","Wilno","Luksemburg","Skopje","Valletta","Monako","Kiszyni�w","Berlin","Oslo","Warszawa","Lizbona","Moskwa","Bukareszt","San Marino","Belgrad","Berno","Sztokholm","Bratys�awa","Lublana","Ankara","Kij�w","Watykan","Londyn","Douglas","Thorshavn","Budapeszt","Rzym","Ryga","The Valley","Saint John's","Buenos Aires","Oranjestad","Nassau","Bridgetown","Belmopan","Hamilton","Sucre","Kralendijk","Brasilia","Road Town","Santiago","Willemstad","Roseau","Santo Domingo","Quito","Stanley","Saint George's","Nuuk","Georgetown","Kajenna","Basse-Terre","Gwatemala","Port-au-Prince","Tegucigalpa","Kingston","George Town","Ottawa","Bogota","San Jos�","Hawana","Fort-de-France","Meksyk","Plymouth","Managua","Panama","Asunci�n","Lima","San Juan","Basseterre","Castries","Kingstown","Saint-Pierre","San Salvador","Waszyngton, D.C.","Paramaribo","Port-of-Spain","Cockburn Town","Montevideo","Caracas","Charlotte Amalie","Canberra","Suva","Hag\xe5t\xf1\x61","Tarawa","Capital Hill","Palikir","Yaren","Alofi","Kingston","Numea","Wellington","Ngerulmud","Port Moresby","Adamstown","Papeete","Apia","Fagatogo","Nuku'alofa","Funafuti","Port Vila","Mata Utu","Avarua","Majuro","Honiara"};


int losuj()
{
    int w = rand() % zapytania.size();
    int ww = zapytania[w];
    zapytania.erase(zapytania.begin() + w );
    return ww;

}

void Afryka()
{
    int pkt=0;

    for(int i=0; i<58; i++) zapytania.push_back(i);
    cout<<"\t\tRunda 1/25\tPunkt�w: 0\t�\n\n\n";
    getline(cin,kontynent);

    for(int i=0; i<25; i++)
    {

        int wylosowana = losuj();
        //cout<<"Wylosowana: "<<wylosowana<<"\n";
        cout<<"\n\nStolica "<<krajeAF[wylosowana]<<" to:\n";
        string odp;
        getline(cin,odp);
        system("cls");
        //if(odp=="111")cout<<"TTA";
        //cout<<"\nOdpowiedzia3eo: "<<odp<<"\n\n";
        if(odp==stoliceAF[wylosowana]) {cout<<"Dobrze!\t\t";pkt++;} else cout<<zle;
        cout<<"Runda "<<(i<24?i+2:25)<<"/25\tPunkt�w: "<<pkt<<"\t�\n";
        cout<<"Stolica "<<krajeAF[wylosowana]<<" to "<<stoliceAF[wylosowana]<<".\n\n";
    }
}


void Azja()
{
    int pkt=0;

    for(int i=0; i<51; i++) zapytania.push_back(i);
    cout<<"\t\tRunda 1/25\tPunkt�w: 0\n\n\n";
    getline(cin,kontynent);

    for(int i=0; i<25; i++)
    {

        int wylosowana = losuj();
        //cout<<"Wylosowana: "<<wylosowana<<"\n";
        cout<<"\n\nStolica "<<krajeAZ[wylosowana]<<" to:\n";
        string odp;
        getline(cin,odp);
        system("cls");
        //if(odp=="111")cout<<"TTA";
        //cout<<"\nOdpowiedzia3eo: "<<odp<<"\n\n";
        if(odp==stoliceAZ[wylosowana] || (wylosowana==17 && odp=="Jerozolima")) {cout<<"Dobrze!\t\t";pkt++;} else cout<<zle;
        cout<<"Runda "<<(i<24?i+2:25)<<"/25\tPunkt�w: "<<pkt<<"\n";
        cout<<"Stolica "<<krajeAZ[wylosowana]<<" to "<<stoliceAZ[wylosowana]<<".\n\n";
    }
}

void Europa()
{
    int pkt=0;

    for(int i=0; i<51; i++) zapytania.push_back(i);
    cout<<"\t\tRunda 1/25\tPunkt�w: 0\t�\n\n\n";
    getline(cin,kontynent);

    for(int i=0; i<25; i++)
    {

        int wylosowana = losuj();
        //cout<<"Wylosowana: "<<wylosowana<<"\n";
        cout<<"\n\nStolica "<<krajeEU[wylosowana]<<" to:\n";
        string odp;
        getline(cin,odp);
        system("cls");
        //if(odp=="111")cout<<"TTA";
        //cout<<"\nOdpowiedzia3eo: "<<odp<<"\n\n";
        if(odp==stoliceEU[wylosowana]) {cout<<"Dobrze!\t\t";pkt++;} else cout<<zle;
        cout<<"Runda "<<(i<24?i+2:25)<<"/25\tPunkt�w: "<<pkt<<"\t�\n";
        cout<<"Stolica "<<krajeEU[wylosowana]<<" to "<<stoliceEU[wylosowana]<<".\n\n";
    }
}


void Ameryka()
{
    int pkt=0;

    for(int i=0; i<52; i++) zapytania.push_back(i);
    cout<<"\t\tRunda 1/25\tPunkt�w: 0\t�\n\n\n";
    getline(cin,kontynent);

    for(int i=0; i<25; i++)
    {

        int wylosowana = losuj();
        //cout<<"Wylosowana: "<<wylosowana<<"\n";
        cout<<"\n\nStolica "<<krajeAM[wylosowana]<<" to:\n";
        string odp;
        getline(cin,odp);
        system("cls");
        //if(odp=="111")cout<<"TTA";
        //cout<<"\nOdpowiedzia3eo: "<<odp<<"\n\n";
        if(odp==stoliceAM[wylosowana] || (wylosowana==45 && odp=="Waszyngton")) {cout<<"Dobrze!\t\t";pkt++;} else cout<<zle;
        cout<<"Runda "<<(i<24?i+2:25)<<"/25\tPunkt�w: "<<pkt<<"\t�\n";
        cout<<"Stolica "<<krajeAM[wylosowana]<<" to "<<stoliceAM[wylosowana]<<(wylosowana==45?"\n\n":".\n\n");
    }
}

void Australia()
{
    int pkt=0;

    for(int i=0; i<24; i++) zapytania.push_back(i);
    cout<<"\t\tRunda 1/24\tPunkt�w: 0\t";SetConsoleOutputCP(1252);cout<<"\xe5 \xf1\n\n\n";SetConsoleOutputCP(1250);
    getline(cin,kontynent);

    for(int i=0; i<24; i++)
    {

        int wylosowana = losuj();
        //cout<<"Wylosowana: "<<wylosowana<<"\n";
        cout<<"\n\nStolica "<<krajeAO[wylosowana]<<" to:\n";
        string odp;


        if(wylosowana==2) SetConsoleCP(1252);

        getline(cin,odp);
        if(wylosowana==2) SetConsoleCP(1250);

        system("cls");
        //if(odp=="111")cout<<"TTA";
        //cout<<"\nOdpowiedzia3eo: "<<odp<<"\n\n";

        if(odp==stoliceAO[wylosowana]) {cout<<"Dobrze!\t\t";pkt++;} else cout<<zle;
        cout<<"Runda "<<(i<23?i+2:24)<<"/24\tPunkt�w: "<<pkt<<"\t";SetConsoleOutputCP(1252);cout<<"\xe5 \xf1\n";SetConsoleOutputCP(1250);

        if(wylosowana==2)
        {
            SetConsoleOutputCP(1252);
            cout<<"Stolica Guamu to Hag\xe5t\xf1"<<"a.\n\n";
            SetConsoleOutputCP(1250);
        }
        else
        cout<<"Stolica "<<krajeAO[wylosowana]<<" to "<<stoliceAO[wylosowana]<<".\n\n";
    }
}


void Swiat()
{
    int pkt=0;

    for(int i=0; i<236; i++) zapytania.push_back(i);
    cout<<"\t\tRunda 1/70\tPunkt�w: 0\t� � ";SetConsoleOutputCP(1252);cout<<"\xe5 \xf1\n\n\n";SetConsoleOutputCP(1250);
    getline(cin,kontynent);

    for(int i=0; i<70; i++)
    {

        int wylosowana = losuj();
        //cout<<"Wylosowana: "<<wylosowana<<"\n";
        cout<<"\n\nStolica "<<krajeSW[wylosowana]<<" to:\n";
        string odp;

        if(wylosowana==214) SetConsoleCP(1252);

        getline(cin,odp);
        if(wylosowana==214) SetConsoleCP(1250);

        system("cls");
        //if(odp=="111")cout<<"TTA";
        //cout<<"\nOdpowiedzia3eo: "<<odp<<"\n\n";
        if(odp==stoliceSW[wylosowana] || (wylosowana==205 && odp=="Waszyngton") || (wylosowana==75 && odp=="Jerozolima")) {cout<<"Dobrze!\t\t";pkt++;} else cout<<zle;
        cout<<"Runda "<<(i<69?i+2:70)<<"/70\tPunkt�w: "<<pkt<<"\t� � ";SetConsoleOutputCP(1252);cout<<"\xe5 \xf1\n";SetConsoleOutputCP(1250);


        if(wylosowana==214)
        {
            SetConsoleOutputCP(1252);
            cout<<"Stolica Guamu to Hag\xe5t\xf1"<<"a.\n\n";
            SetConsoleOutputCP(1250);
        }
        else
        cout<<"Stolica "<<krajeSW[wylosowana]<<" to "<<stoliceSW[wylosowana]<<(wylosowana==205?"\n\n":".\n\n");
    }
}


void CalySwiat()
{
    int pkt=0;

    for(int i=0; i<236; i++) zapytania.push_back(i);
    cout<<"\t\tRunda 1/236\tPunkt�w: 0\t� � ";SetConsoleOutputCP(1252);cout<<"\xe5 \xf1\n\n\n";SetConsoleOutputCP(1250);
    getline(cin,kontynent);

    for(int i=0; i<236; i++)
    {

        int wylosowana = losuj();
        //cout<<"Wylosowana: "<<wylosowana<<"\n";
        cout<<"\n\nStolica "<<krajeSW[wylosowana]<<" to:\n";
        string odp;

        if(wylosowana==214) SetConsoleCP(1252);

        getline(cin,odp);
        if(wylosowana==214) SetConsoleCP(1250);

        system("cls");
        //if(odp=="111")cout<<"TTA";
        //cout<<"\nOdpowiedzia3eo: "<<odp<<"\n\n";
        if(odp==stoliceSW[wylosowana] || (wylosowana==205 && odp=="Waszyngton") || (wylosowana==75 && odp=="Jerozolima")) {cout<<"Dobrze!\t\t";pkt++;} else cout<<zle;
        cout<<"Runda "<<(i<235?i+2:236)<<"/236\tPunkt�w: "<<pkt<<"\t� � ";SetConsoleOutputCP(1252);cout<<"\xe5 \xf1\n";SetConsoleOutputCP(1250);


        if(wylosowana==214)
        {
            SetConsoleOutputCP(1252);
            cout<<"Stolica Guamu to Hag\xe5t\xf1"<<"a.\n\n";
            SetConsoleOutputCP(1250);
        }
        else
        cout<<"Stolica "<<krajeSW[wylosowana]<<" to "<<stoliceSW[wylosowana]<<(wylosowana==205?"\n\n":".\n\n");
    }
}


int main()
{
    srand(time(NULL));
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    setlocale(LC_ALL, "1250");
    /*cout<<"Hag\xe5t"<<"\xf1"<<"a";

    string ooo="Hag\xe5t\xf1\x61";
    //cin>>ooo;
    cout<<ooo;
    string aaa;
    cin>>aaa;
    if(aaa==ooo)cout<<"TAK";else cout<<"NIE";
    //if(ooo=="Hag\xe5t\xf1a")
    return 0;*/
    /*string test;
    cin>>test;
    std::ofstream out("output.txt");
    out << test;
    out.close();
    return 0;*/

    /*for(int i=0; i<236; i++)
    {
        cout<<i<<". "<<krajeSW[i]<<" "<<stoliceSW[i]<<"\n";
    }*/


    while(kontynent!="1"&&kontynent!="2"&&kontynent!="3"&&kontynent!="4"&&kontynent!="5"&&kontynent!="6"&&kontynent!="7")
    {
        cout<<"[1] Afryka\n[2] Azja\n[3] Europa\n[4] Ameryka\n[5] Australia i Oceania\n[6] �wiat\n[7] �wiat (wszystkie kraje)\n";
        cin>>kontynent;
        system("cls");
    }

    switch (kontynent[0])
    {
    case '1':
        Afryka();
        break;
    case '2':
        Azja();
        break;
    case '3':
        Europa();
        break;
    case '4':
        Ameryka();
        break;
    case '5':
        Australia();
        break;
    case '6':
        Swiat();
        break;
    case '7':
        CalySwiat();
        break;
    }
    //_set_mode(_fileno(stdout), _0_U16TEXT);

    system("pause");
}
