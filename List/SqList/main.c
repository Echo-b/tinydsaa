#include "dynamic_sqlist.c"

int main()
{
    dynamic_sqlist_t d_sql;
    init(&d_sql);
    ElementType e = 3;
    add(&d_sql, 1, 1);
    add(&d_sql, 3, 2);
    add(&d_sql, 4, 3);
    add(&d_sql, 7, 4);
    add(&d_sql, 9, 5);
    add(&d_sql, 11, 6);

    dynamic_sqlist_t new_sql;
    init(&new_sql);
    add(&new_sql, 3, 1);
    add(&new_sql, 6, 2);
    add(&new_sql, 8, 3);
    add(&new_sql, 12, 4);

    dynamic_sqlist_t com_sql;
    merge_sqlist(d_sql, new_sql, &com_sql);
    display(com_sql);
    return 0;
}