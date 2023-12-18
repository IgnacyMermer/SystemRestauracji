# Założenia projektu: 
Wykonaliśmy aplikacje desktopową na system Windows oraz Macos. Aplikacja pozwala na zarządzanie restauracją oraz sprawną komunikacje z klientem,
edycję dań, przyjmowanie zamówień oraz ich podgląd. Aplikacja pozwala również na dodawanie zadań dla innych pracowników. 
Pozwala na oznaczenie zadania jako wykonanego i podgląd tych zadań, które zostały wykonane wcześniej. 
Aplikacja posiada równeż panel każdego klienta i pracownika, w którym można przeglądać historię zamówien bądź też zadań, obowiązków.
#
Do stworzenia UI aplikacji wykorzystaliśmy bibliotekę Qt5. Pozwoliła ona stworzyć inny wygląd dla każdej akcji, którą chcieliśmy przetworzyć w naszym systemie
restauracyjnym. Biblioteka ta pozwoliła nam również stworzyć aplikację kompatybilną na każdym desktopowym systemie operacyjnym. Aplikacja wygląda przystępnie 
niestety tylko na szerokości widoku aplikacji 551x989 pixeli.

# Klasy:

- Order (klasa przechowuje informacje o zamówieniach złożonych przez klientów, przechowuje dane o dacie 
złożenia zamówienia, zamówionych posiłkach, kliencie który składał to zamówienie i cenie całkowitej)
- Meal (klasa jest nadklasą dla struktur tj. Mainmeal przechowujących informacje o posiłkach i daniach 
oferowanych w restauracji. Pozwala określić składniki, które składają się na dane danie, oraz nazwę i cenę.)
- Data (klasa posiadająca dwie podklasy: GetData, PostData. Pozwala ona na komunikacje z API, wysylanie zapytań 
HTTP GET oraz HTTP POST. Ma ona również funkcje pozwalające tworzyć treść przesyłanego _body_ w zapytaniu POST. 
Pozwala również na sprawniejsze pobranie listy produktów do wektora typu klasy _Meal_.)
- Employee (klasa przechowuje informacje o zalogowanym pracowniku. Przetrzymuje takie informacje jak imie i nazwisko, login, 
pozycja na jakiej pracuje dany pracownik)
- Client (klasa przechowuje informacje o kliencie. Przetrzymuje takie dane jak imię i nazwisko, login)

### Biblioteki, które zostału użyte w projekcie: 
- Qt5 (https://doc.qt.io/qt-5/)
- NodeJS (https://nodejs.org/en)
- MongoDB (https://www.mongodb.com)
- Curlpp (http://www.curlpp.org)
- Json_spirit (https://github.com/cierelabs/json_spirit)
- Boost (https://www.boost.org)
- GoogleTest (https://github.com/google/googletest)

### Backend
W naszej aplikacji, aby sprawniej komunikować się z bazą danych stworzyliśmy backend w języku NodeJS.
Z użyciem biblioteki mongoose łączymy się z naszą bazą danych (MongoDB). 
Pozwala ona, podczas działania na localhost, na wysyłanie zapytań HTTP i na ich przetwarzanie, pobieranie 
danych oraz wysyłanie odpowiednich zapytań z tymi danymi do bazy danych. Backend inaczej API pozwala rozbudowywać 
aplikacje jeszcze bardziej, właśnie dzięki niemu moglibyśmy stworzyć inną aplikację, np. dla kierowców dowożących jedzenie
i działała by ona na tych samych danych, a jej stworzenie nie zaburzyłoby działania pierwotnego systemu. 

<img width="1030" alt="Zrzut ekranu 2023-12-18 o 15 45 32" src="https://github.com/IgnacyMermer/SystemRestauracji/assets/60555082/64787d4c-e372-4845-a4c5-d6239ee907b4">
<img width="793" alt="Zrzut ekranu 2023-12-18 o 15 43 48" src="https://github.com/IgnacyMermer/SystemRestauracji/assets/60555082/7408722c-c9f3-43e1-96f3-f223ccb291a9">
