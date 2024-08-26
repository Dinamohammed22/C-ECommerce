void addCategory(supermarket * super)
{
    char ch;
    do
    {
        super->category=realloc(super->category,(super->catSize+1)*sizeof(category));
        char catName[20];
        printf("enter category name : ");
        scanf("%s",catName);
       int index=findIndex(super,catName);
    if(index!=-1)
        {
            printf("this category already exists please enter another name\n");
        }
        else
        {

            strcpy(super->category[super->catSize].cat_name,catName);
            super->category[super->catSize].productCount=0;
            (super->catSize)++;
            printf("You added category successfully \n");
        }

        printf("do you want to add another category ? (y/n)\n");
        ch=getche();
    }
    while(ch=='y'||ch=='Y');

}
