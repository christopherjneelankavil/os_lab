echo "enter the number : "
read n
((half=n/2))
i=0
while((half>=2))
do
    if((n%half==0))
    then
        i=1
        break
    else
        ((half--))
    fi
done 

if(($i==1 && $n!=1))
then
    echo "not prime"
else
    echo "prime"
fi