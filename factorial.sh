echo "enter the number: "
read n
factorial=1
while((n>0))
do 
    ((factorial*=n))
    ((n--))
done

echo "factorial : $factorial"