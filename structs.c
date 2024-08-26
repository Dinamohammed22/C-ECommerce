
typedef struct category category;
typedef struct product product;
typedef struct supermarket supermarket;


struct supermarket{
category * category;
int catSize;
};

struct category
{
    char cat_name[20];
    product *product;
    int productCount;

};
struct product
{
    char product_name[20];
    int quantity , price;

};


