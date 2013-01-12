cat << "------" | gnuplot --persist
set xlabel "year"
set ylabel "average temperature"
set yrange [0:22]
set key off
plot '-' with boxes
2000, 18
2001, 20
2002, 10
2003, 14
2004, 16
2005, 10
2006, 12
2007, 20
2008, 8
2009, 18
2010, 12
2011, 14
2012, 10
e
------
