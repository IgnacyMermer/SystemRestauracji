# Założenia projektu: 
Wykonaliśmy aplikacje desktopową na system Windows oraz Macos. Aplikacja pozwala na zarządzanie restauracją oraz sprawną komunikacje z klientem,
edycję dań, przyjmowanie zamówień oraz ich podgląd. Aplikacja pozwala również na dodawanie zadań dla innych pracowników. 
Pozwala na oznaczenie zadania jako wykonanego i podgląd tych zadań, które zostały wykonane wcześniej. 
Aplikacja posiada równeż panel każdego klienta i pracownika, w którym można przeglądać historię zamówien bądź też zadań, obowiązków.

# Klasy:

- Order
- Meal
- Data
- Employee
- Client

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
