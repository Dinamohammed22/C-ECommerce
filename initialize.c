void initialize (supermarket * super)
{
    super->catSize=2;
    super->category=(category *)malloc(super->catSize * sizeof(category));
    for(int i=0; i<2; i++)
    {
        super->category[i].productCount=2;
        super->category[i].product=(product *)malloc(super->category->productCount * sizeof(product));

    }

    strcpy(super->category[0].cat_name,"dairy");
    strcpy(super->category[1].cat_name,"meat");

    strcpy(super->category[0].product[0].product_name,"milk");
    strcpy(super->category[0].product[1].product_name,"cheese");

    strcpy(super->category[1].product[0].product_name,"beef");
    strcpy(super->category[1].product[1].product_name,"chicken");

    super->category[0].product[0].quantity=2;
    super->category[0].product[1].quantity=3;

     super->category[1].product[0].quantity=5;
     super->category[1].product[1].quantity=22;

    super->category[0].product[0].price=20;
    super->category[0].product[1].price=40;

    super->category[1].product[0].price=100;
    super->category[1].product[1].price=200;


}
