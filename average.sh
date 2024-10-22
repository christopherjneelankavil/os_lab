echo "enter the limit: "
read limit 
i=0
sum=0
while((i<=limit))
do 
    ((sum=sum+i))
    ((i=i+1))
done

((avg=sum/limit))

echo "average is : $avg" 
