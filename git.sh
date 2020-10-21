#printf "would you like to commit? (y/n): "
#read choice
#if [ $choice == 'y' ]
#then
    printf "What is the commit message: \n\n\n\n\n"
    read var
    echo $var
    git add .
    git commit -m "$var"
#fi


# printf "printf \"would you like to commit? (y/n): \"\nread choice\nif [ $choice == 'y' ]\nthen\nprintf \"What is the commit message: \n\n\n\n\n\"\nread var\necho $var\ngit add .\ngit commit -m \"$var\"\nfi"
