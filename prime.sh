echo "enter the number: "
read n
flag=0
for ((i=2;i<=n/2;i++))
do
    if((n%i==0))
        then 
            flag=1
            break
    fi
done  
if((flag==1))
    then 
        echo "The given number is not prime"
    else 
        echo "The given number is prime"
fi
            