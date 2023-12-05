#include <stdio.h>
#include <stdlib.h>

struct jsw_node
{
    int red;
    int data;
    struct jsw_node* link[2];
};

struct jsw_node* make_node(int data)
{
    struct jsw_node* vertex = (struct jsw_node*)malloc(sizeof(struct jsw_node));
    if (vertex)
    {
        vertex->data = data;
        vertex->red = 0;
        vertex->link[0] = NULL;
        vertex->link[1] = NULL;

        return vertex;
    }
}

struct jsw_node* jsw_insert(struct jsw_node* root, int data)
{
    if (root == NULL)
    {
        root = make_node(data);
    }
    else
    {
        int dir = root->data < data;

        root->link[dir] = jsw_insert(root->link[dir], data);
    }

    return root;
}

struct jsw_node* jsw_single(struct jsw_node* root, int dir)
{
    struct jsw_node* save = root->link[!dir];

    root->link[!dir] = save->link[dir];
    save->link[dir] = root;

    root->red = 1;
    save->red = 0;

    return save;
}

struct jsw_node* jsw_double(struct jsw_node* root, int dir)
{
    root->link[!dir] = jsw_single(root->link[!dir], !dir);

    return jsw_single(root, dir);
}

int main(void)
{
    struct jsw_node* head = NULL;
    head = jsw_insert(head, 10);
    head = jsw_insert(head, 20);
    head = jsw_insert(head, 30);

	return 0;
}