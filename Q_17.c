//Q17 Write a program in C to swap (interchange) the first and last column of a given matrix

#include <stdio.h>
 
int main()
{
    static int array1[10][10], array2[10][10];
    int i, j, m, n, a, b, c, p, q, r;
 
        printf("Enter no. of rows :: ");
        scanf("%d", &m);
        printf("\nEnter no. of cols :: ");
        scanf("%d",&n);
        printf("\nEnter values to the matrix :: \n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                 printf("\nEnter a[%d][%d] value :: ",i,j);
                 scanf("%d", &array1[i][j]);
                 array2[i][j] = array1[i][j];
        }
    }
    
    printf("\nThe given matrix is \n\n");
        for (i = 0; i < m; ++i)
        {
        for (j = 0; j < n; ++j)
        {
            printf("\t%d", array1[i][j]);
        }
        printf("\n\n");
    }
    
    
    printf("\nEnter row number to be exchanged : ");
    scanf("%d", &a);
    printf("\nEnter other row number to be exchanged with : ");
    scanf("%d",&b);
    
    for (i = 0; i < m; ++i)
    {
        /*  first row has index is 0 */
        c = array1[a - 1][i];
        array1[a - 1][i] = array1[b - 1][i];
        array1[b - 1][i] = c;
    }
    printf("\nEnter col number to be exchanged : ");
    scanf("%d", &p);
    printf("\nEnter other col number to be exchanged with : ");
    scanf("%d",&q);
    
    for (i = 0; i < n; ++i)
    {
        /*  first column index is 0 */
        r = array2[i][p - 1];
        array2[i][p - 1] = array2[i][q - 1];
        array2[i][q - 1] = r;
     }
    printf("\nThe matix after interchanging the two rows ::  \n");
    for (i = 0; i < m; ++i)
        {
        for (j = 0; j < n; ++j)
        {
            printf("\t%d", array1[i][j]);
        }
        printf("\n\n");
    }
    
    printf("\nThe matix after interchanging the two columns :: \n");
    
    for (i = 0; i < m; ++i)
        {
        for (j = 0; j < n; ++j)
        {
            printf("\t%d", array2[i][j]);
        }
        printf("\n\n");
    }
    
    return 0;
}