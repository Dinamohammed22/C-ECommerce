void moveProduct(supermarket *super)
{
char ch;
    do
    {
        char name1[20],name2[20];
        printf("enter category name to remove product from : ");
        scanf("%s",name1);
        int index1 =findIndex(super,name1);
        if(index1==-1)
        {
            printf("this category doesn't exist try again\n");
        }
        else
        {
            printf("enter category name to remove product to : ");
            scanf("%s",name2);
            int index2 =findIndex(super,name2);
            if(index2==-1)
            {
                printf("this category doesn't exist try again\n");

            }
            else
            {

                char productName[20];
                printf("enter product name to move from %s to %s : \n",name1,name2);
                scanf("%s",productName);
                int indexProduct=findPindex(super,index1,productName);
                if(indexProduct==-1)
                {
                    printf("this product doesn't exist\n");
                }
                else
                {
                    realloc(super->category[index2].product,((super->category[index2].productCount))*sizeof(product));
                    strcpy(super->category[index2].product[super->category[index2].productCount].product_name,(super->category[index1].product[indexProduct].product_name));
                    super->category[index2].product[super->category[index2].productCount].price=(super->category[index1].product[indexProduct].price);
                    super->category[index2].product[super->category[index2].productCount].quantity=(super->category[index1].product[indexProduct].quantity);
                    (super->category[index2].productCount)++;

                    for(int i=indexProduct; i<super->category[index1].productCount; i++)
                    {
                        strcpy(super->category[index1].product[i].product_name,super->category[index1].product[i+1].product_name);
                        super->category[index1].product[i].quantity=super->category[index1].product[i+1].quantity;
                        super->category[index1].product[i].price=super->category[index1].product[i+1].price;

                    }
                    (super->category[index1].productCount)--;
                    printf("product moved successfully\n");

                }
            }

        }
        printf("do you want to remove another category ? (y/n)\n");
        ch=getche();
    }while(ch=='y'||ch=='Y');
}
