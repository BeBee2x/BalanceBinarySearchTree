#include "stdio.h"
#include "stdlib.h"

int array[1000];

void get_data_from_file(){

    FILE *fptr = fopen("data.txt","r");
    if(fptr==NULL){
        printf("Can't open file.Try again\n");
    }else{

        int i=0;
        while(!feof(fptr)){

            fscanf(fptr,"%d",&array[i]);
            i++;

        }

    }

    fclose(fptr);

}

struct node{

    int data;
    struct node* left;
    struct node* right;

};

struct node* createNode(int data){

    struct node* newNode = (struct node*) malloc(sizeof (struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;

}

struct node* insert_node_inBalance(int start,int end){

    if(start>end){
        return NULL;
    }

    int root_data = ( start + end ) / 2;

    struct node* root = createNode(root_data);

    int start_index = start-1;
    int end_index = end-1;
    int root_data_index = root_data-1;

    root->left = insert_node_inBalance(array[start_index],array[root_data_index]-1);
    root->right = insert_node_inBalance(array[root_data_index]+1,array[end_index]);

    return root;

}

void inorderTraversal(struct node* node){

    if(node==NULL){
        return;
    }else{
        inorderTraversal(node->left);
        printf("%d ",node->data);
        inorderTraversal(node->right);
    }

}


int main(){

    struct node* root = NULL;

    get_data_from_file();

    int array_size = sizeof (array) / sizeof (array[0]);

    int start =array[0];

    int end = array[array_size-1];

    root = insert_node_inBalance(start,end);

    printf("Inseting data complete!\n");

    printf("This is your data\n");

    inorderTraversal(root);

    return 0;
}

