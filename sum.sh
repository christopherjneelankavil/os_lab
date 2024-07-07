echo "enter the limit: "
read limit

i=0
sum=0
while((i<=limit))
do 
    ((sum+=i))
    ((i++))
done

echo "sum is : $sum"