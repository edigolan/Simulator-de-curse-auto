# Simulator-de-curse-auto
Masini diferite, circuite si conditii meteo variabile
# I Definirea claselor:

# Masina:
 Rolul acestei clase este de a defini comportamentul general al unei mașini în cadrul cursei. Metoda update simulează mișcarea mașinii, iar altele ca "getDistantaParcursa" sunt utile pentru gestionarea și urmărirea poziției..<br/>
# MasinaSport:
Rolul acestei clase este să modifice comportamentul mașinilor sport, care sunt mai rapide și au o accelerație diferită în comparație cu mașinile obișnuite. Suprascrierea metodei "update" permite o gestionare specială a mișcării.<br/>
# Cursa: 
Rolul acestei clase este de a organiza și controla cursa, gestionând mașinile, obstacolele și afișarea animată a stării cursei. Metoda "incepe" implementează logica principală a cursei, iar "adaugaMasina" și "afisareAnimata" contribuie la adăugarea mașinilor și la vizualizarea evoluției cursei.<br/>
# Circuit: 
Rolul acestei clase este să definească parametrii unui circuit pe care se va desfășura cursa. Aceasta este folosită de clasa "Cursa" pentru a determina lungimea și denumirea circuitului.
# II.Simularea completa a cursei:

Simularea completă a cursei, așa cum este implementată în acest cod, urmărește desfășurarea unei competiții între mai multe mașini pe un circuit ales de utilizator. Procesul este împărțit în mai mulți pași, începând cu inițializarea cursei și terminând cu determinarea câștigătorului și afișarea clasamentului final. Mai jos, voi descrie detaliat fiecare etapă a simulării.<br/>

# 1. Inițializarea și selectarea circuitului

La început, sunt create mai multe obiecte de tip Circuit, fiecare având o lungime și un nume diferit (ex: Monza, Silverstone, Nurburgring etc.). Fiecare circuit reprezintă o pistă pe care va avea loc competiția.<br/>
Utilizatorul este invitat să aleagă un circuit dintre opțiunile disponibile.<br/>
După alegerea circuitului, se creează o instanță de Cursa, care va organiza și gestiona întreaga simulare.<br/>

# 2. Adăugarea mașinilor

După alegerea circuitului, se adaugă mai multe mașini la cursă. În acest caz, sunt adăugate patru mașini, dintre care două sunt mașini sport și două sunt mașini obișnuite:<br/>
-Masina("Dacia", 120, 2.5): O mașină cu viteză maximă de 120 km/h și accelerație de 2.5 m/s².<br/>
-MasinaSport("Ferrari", 320, 5.5): O mașină sport cu viteză maximă de 320 km/h și accelerație de 5.5 m/s².<br/>
-Masina("Toyota", 200, 4.0): O mașină cu viteză maximă de 200 km/h și accelerație de 4.0 m/s².<br/>
-MasinaSport("Lamborghini", 350, 6.0): O mașină sport cu viteză maximă de 350 km/h și accelerație de 6.0 m/s².<br/>
Fiecare mașină este asociată cu un obiect de tip Masina sau MasinaSport, iar acestea sunt adăugate într-un vector de mașini, care va fi gestionat de clasa Cursa.<br/>

# 3. Generarea obstacolelor

După adăugarea fiecărei mașini, este generată o matrice de obstacole aleatorii pentru fiecare mașină. Această matrice are 50 de elemente (corespunzătoare celor 50 de puncte de pe circuit) și este folosită pentru a simula obstacole care pot afecta mașinile pe parcursul cursei.<br/>
Fiecare element din matrice este un bool care poate fi true (obstacol) sau false (fără obstacol). Obstacolele sunt generate cu o probabilitate de 20%, astfel încât există șanse ca fiecare mașină să întâmpine obstacole pe circuit.<br/>

# 4. Desfășurarea cursei (incepe() method)

Startul cursei:<br/>
-Cursa începe cu un mesaj de informare, iar mașinile se pregătesc să concureze pe circuitul ales.<br/>
Simularea fiecărei etape:<br/>
-Cursa continuă într-un ciclu până când toate mașinile ajung la linia de sosire. La fiecare iterație a ciclului, se execută următoarele acțiuni:<br/>
Calcularea distanței parcurse:<br/>
Fiecare mașină își actualizează distanța parcursă pe bază de viteză și accelerație. Distanța este calculată folosind formula fizică:<br/>
distantaParcursa += 0.5 * (acceleratie * 1.2) * timp * timp<br/>

# 5. Finalizarea cursei:

Cursa continuă până când toate mașinile au terminat circuitul sau cel puțin una ajunge la linia de sosire.<br/>
Determinarea câștigătorului: Dacă o mașină atinge linia de sosire, aceasta este considerată câștigătoare. Programul anunță câștigătorul și afișează mesajul de felicitare.<br/>
Clasamentul:<br/>
-După încheierea cursei, mașinile sunt sortate în funcție de distanța parcursă (folosind std::sort), iar programul afișează clasamentul final al mașinilor, indicând ordinea acestora în funcție de performanță.
