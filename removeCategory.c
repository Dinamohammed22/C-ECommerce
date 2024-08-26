void removeCategory(supermarket * super)
{
    char ch;
    do
    {
        char name[20];
        printf("enter category name to delete : ");
        scanf("%s",name);

        int index =findIndex(super,name);

        if(index==-1)
        {
            printf("this category doesn't exist\n");
        }
        else
        {
            for(int i=index; i<(super->catSize); i++)
            {
                strcpy(super->category[i].cat_name,super->category[i+1].cat_name);
            }
            (super->catSize)--;
            printf("category removed successfully\n");
        }
        printf("do you want to remove another category ? (y/n)\n");
        ch=getche();
    }
    while(ch=='y'||ch=='Y');
}
