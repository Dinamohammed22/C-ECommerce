
void addProduct(supermarket * super)
{
    char ch;
    do
    {
        char catName[20];
        printf("enter category you want to add product in : ");
        scanf("%s",catName);
        printf("\n");

        int index=findIndex(super,catName);

        if(index==-1)
        {
            printf("this category doesn't exist\n");
        }
        else
        {
           //printf("%s\n",super->category[index].cat_name);
            if(super->category[index].productCount==0){
            //super->category[index].productCount++;
             super->category[index].product=(product *)malloc((super->category[index].productCount)+1 * sizeof(product));
            }else{
            //super->category[index].productCount++;
            realloc(super->category[index].product,((super->category[index].productCount))*sizeof(product));
            }
            char productName[20];
            int quantity,price;
            printf("enter product name : ");
            scanf("%s",productName);
            printf("\n");
            printf("enter quantity : ");
            scanf("%i",&quantity);
            printf("\n");
            printf("enter price : ");
            scanf("%i",&price);
            printf("\n");
            int indexProduct=findPindex(super,index,productName);
            if(indexProduct!=-1)
            {
                printf("this product already exists we will just increase the quantity\n");
                (super->category[index].product[indexProduct].quantity)+=quantity;
            }
            else
            {

                strcpy(super->category[index].product[super->category[index].productCount].product_name,productName);
                super->category[index].product[super->category[index].productCount].quantity=quantity;
                super->category[index].product[super->category[index].productCount].price=price;
                (super->category[index].productCount)++;
            }

        }
        printf("do you want to add another product ? (y/n)\n");
        ch=getche();
    }
    while(ch=='y'||ch=='Y');
}
