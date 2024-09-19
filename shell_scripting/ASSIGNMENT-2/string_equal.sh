read -p "Enter a string: " str1
read -p "Enter another string: " str2

if [ "$str1" = "$str2" ]
then
    echo "Both strings are equal"
else
    echo "Both strings are not equal"
fi