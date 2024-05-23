<p>
<img alt="C++" src="https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white" width="60">
<img alt="Git" src="https://img.shields.io/badge/git-%23F05033.svg?style=for-the-badge&logo=git&logoColor=white" width="60">
</p>

<h1> <img src="https://red.utec.edu.uy/wp-content/uploads/2018/11/09-Isotipo-1.png" width="25"/> UTEC - PP - <b>Buscaminas</b></h1>


<p> El juego consta de la exploración de un tablero en el cual existen minas escondidas. El jugador debe explorar completamente dicho tablero 
<b>marcando todas las minas escondida para poder ganar</b> , y perderá la partida si en algún momento hace explotar una mina. <br><em>Su puntaje se definira 
en base al tiempo en que se logre marcar todas las minas escondidas.</em></p>

<h2> </h2>

### Compilar y Jugar

```
git clone https://github.com/MatiasAlfaroDev/UTEC-PP-Buscaminas.git
cd Buscaminas
compilar con c++
./Buscaminas
```
<h2></h2>

<h3> ⚙️ Funcionamiento del Juego</h3>

* Se cuenta con un tablero de 8 x 8
* Cada celda será identificada por los números respectivos de fila y columna.
* En todo el tablero estarán escondidas 16 minas.
  
<em>Inicialmente el tablero mostrará todas las casillas inexploradas. En caso de tener minas adyacentes mostrara el número que tiene. </em>

* En caso de no tener ninguna mina mostrara el carácter vacío <b>‘ ’</b>
* Las casillas marcadas por el jugador como sospechosas son indicadas con una <b>‘x’</b>
* Las casillas con bombas se indican con una <b>‘B’</b>

<h2> </h2>

<h3> <img src= "https://images.emojiterra.com/google/android-12l/512px/1f579.png" width="25 "/> Funcionamiento del Jugador  </h3>

<p>El jugador cuenta con 2 posibles jugadas en cada turno:  <e>[E] Explorar y [M] Marcar</e>.

Para indicar su jugada, <b>el jugador presiona una de las opciones, seguido de un espacio
y luego los números de la fila y la columna, respectivamente.</b> <br> 

* <b>OPCION [E]</b> Revela lo que se encontraba en una casilla previamente inexplorada. 
En caso que la celda no tuviera ninguna mina adyacente deberá expandir la exploración hacia sus celdas vecinas, 
de manera que se finaliza cuando existan celdas con minas adyacentes.

* <b>OPCION [M]</b> Marcar deja marcada como sospechosa una casilla previamente inexplorada, o remueve la marca de una casilla ya marcada. 


<h2> </h2>

<h3> 📜 Reglas del Juego </h3>

* Solo se pueden marcar <b>hasta 16 casillas</b>.
* El jugador gana cuando haya revelado <b>48 casillas</b>.

### Las jugadas sin efecto son:
* Explorar en una casilla que está marcada.
* Marcar o Explorar una casilla ya explorada.
* Marcar o Explorar en casillas inexistentes.
* Utilizar un formato inadecuado de jugada.







