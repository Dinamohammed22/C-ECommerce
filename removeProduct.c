void removeProduct (supermarket * super)
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
            char productName[20];
            printf("enter product name : ");
            scanf("%s",productName);
            int indexProduct=findPindex(super,index,productName);
            if(indexProduct==-1)
            {
                printf("this product doesn't exist\n");
            }
            else
            {

                for(int i=indexProduct; i<super->category[index].productCount; i++)
                {
                    strcpy(super->category[index].product[i].product_name,super->category[index].product[i+1].product_name);
                    super->category[index].product[i].quantity=super->category[index].product[i+1].quantity;
                    super->category[index].product[i].price=super->category[index].product[i+1].price;

                }
                (super->category[index].productCount)--;
                printf("product removed successfully\n");

            }

        }

        printf("do you want to remove another category ? (y/n)\n");
        ch=getche();
    }
    while(ch=='y'||ch=='Y');
}
