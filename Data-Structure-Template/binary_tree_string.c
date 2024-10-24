#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 20

typedef struct node{
    char *value;           
    struct node *p_left;
    struct node *p_right;
}StrTreeNode_t;

typedef int (*Compare)(const char *, const char *);

void insert(char key[MAXLEN+1], StrTreeNode_t** leaf, Compare cmp){
    int res;
    if((*leaf)== NULL){
        (*leaf) = malloc(sizeof(StrTreeNode_t));
        (*leaf)->value = malloc(strlen(key)+1);     
        strcpy ((*leaf)->value, key);                   
        (*leaf)->p_left = NULL;
        (*leaf)->p_right = NULL;
    } 
    else{
        res = cmp(key,(*leaf)->value);
        if(res < 0)
            insert(key, &(*leaf)->p_left, cmp);
        else if(res > 0)
            insert(key, &(*leaf)->p_right, cmp);
        else   //Key Already Exists
            return;
    }
}

int CmpStr(const char *a, const char *b){
    return (strcmp (a, b));   
}

void in_order(StrTreeNode_t *root){
    if( root != NULL ) {
        in_order(root->p_left);
        printf("%s\n", root->value);
        in_order(root->p_right);
    }
}

void search(char key[MAXLEN+1], StrTreeNode_t* leaf, Compare cmp){
    int res;
    if( leaf != NULL ) {
        res = cmp(key, leaf->value);
        if(res < 0)
            search(key, leaf->p_left, cmp);
        else if( res > 0)
            search(key, leaf->p_right, cmp);
        else
            printf("\n'%s' found!\n", key);
    }
    else printf("\nNot in tree\n");
    return;
}

void delete_tree(struct node** leaf){
    if( *leaf != NULL ) {
        delete_tree(&(*leaf)->p_left);
        delete_tree(&(*leaf)->p_right);
        free( (*leaf)->value);
        free( (*leaf) );
    }
}

void menu(){
    printf("\nPress 'i' to insert an element\n");
    printf("Press 's' to search for an element\n");
    printf("Press 'p' to print the tree inorder\n");
    printf("Press 'f' to destroy current tree\n");
    printf("Press 'q' to quit\n");
}

int main()
{
    struct node *p_root = NULL;
    char value[MAXLEN+1];
    char option[2];

    while(option[0] != 'q') {
        menu();
        scanf("%s", option);

        if(option[0] == 'i') {
            scanf("%s", value);
            printf ("Inserting %s\n", value);
            insert(value,  &p_root, (Compare)CmpStr);
        }
        else if(option[0] == 's' ) {
            scanf("%s", value);
            search(value, p_root, (Compare)CmpStr);
        }
        else if(option[0] == 'p' ) {
            in_order(p_root);
        }
        else if(option[0] == 'f' ) {
            delete_tree(&p_root);
            printf("Tree destroyed");
            p_root = NULL;
        }
        else if(option[0] == 'q' ) {
            printf("Quitting\n");
        }
    }

return 0;
}