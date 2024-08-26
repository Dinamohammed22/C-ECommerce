void sell(supermarket * super)
{
    char ch;
    do
    {
        char name[20];
        printf("enter category of the product you want to sell to  : ");
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
            printf("\n");
            int indexProduct=findPindex(super,index,productName);
            if(indexProduct==-1)
            {
                printf("this product doesn't exist\n");
            }
            else
            {
                int quantity;
                printf("enter quantity of product to sell : ");
                scanf("%d",&quantity);
                int quantityfinal=(super->category[index].product[indexProduct].quantity )- quantity;
                if(quantityfinal==0)
                {
                    for(int i=indexProduct; i<super->category[index].productCount; i++)
                    {
                        strcpy(super->category[index].product[i].product_name,super->category[index].product[i+1].product_name);
                        super->category[index].product[i].quantity=super->category[index].product[i+1].quantity;
                        super->category[index].product[i].price=super->category[index].product[i+1].price;

                    }
                    (super->category[index].productCount)--;
                    printf("product removed successfully\n");

                }else if(quantityfinal>0){
                     (super->category[index].product[indexProduct].quantity)=(super->category[index].product[indexProduct].quantity )- quantity;
                    printf("product sold successfully\n");

                }else if(quantityfinal<0){
                    printf("this quantity is too much enter quantity less than %i \n",(super->category[index].product[indexProduct].quantity));

                }
            }

        }

        printf("do you want to sell another product ? (y/n)\n");
        ch=getche();
    }
    while(ch=='y'||ch=='Y');
}
