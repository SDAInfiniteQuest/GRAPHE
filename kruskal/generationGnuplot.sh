#! /bin/sh

dataGraphe(){
>~/GRAPHE/data.txt

val=0
for i in `seq 10 10 1000`
	do 
		/usr/bin/time -f "%e" -a -o data.txt ./bin/exo1 -s -r -$1 -$2 -t $i >> data.txt
	done
taille=`wc -l data.txt | cut -f 1 -d" "`

for i in `seq 1 $taille` 
	do
		val=`expr $i \* 10`
		val="$val " 
		sed -i "$i s/^/$val/" data.txt
	done
}

	
CreerScriptGnuplot(){
	

	echo "
	set terminal png size 600,300
	set output '$1 '
	set ylabel 'temps d execution en secondes'
	set xlabel 'nombre de sommet'

	plot \"data.txt\"  title '$1' with linespoint 
	" > gnuplot.spl

}

dataGraphe "c" "n"
CreerScriptGnuplot "graphe non-oriente complet avec sommet n.png" 
cat gnuplot.spl | gnuplot


dataGraphe "c" "o"
CreerScriptGnuplot "graphe oriente complet avec sommet n.png" 
cat gnuplot.spl | gnuplot

dataGraphe "p" "n"
CreerScriptGnuplot "graphe non-oriente partiel avec sommet n.png" 
cat gnuplot.spl | gnuplot

dataGraphe "p" "o"
CreerScriptGnuplot "graphe oriente partiel avec sommet n.png" 
cat gnuplot.spl | gnuplot

