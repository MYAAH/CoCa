make $1
./$1 $2
./glucose-syrup-4.1/simp/glucose out.txt outG.txt
make get_tree_$1
clear
./get_tree_$1 outG.txt
