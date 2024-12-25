// HCM_KS24B_TranHoangDuy_N24DTCN021_01

#include <stdio.h>

#include <math.h>

const int MAX_SIZE = 100;

int SIZE = 0; 

int main () 
{
    int array[MAX_SIZE];

    int choices;

    while(1)
    {
        printf("\n");
        
        printf("\n++++++++++ MENU: ++++++++++\n");
        
        printf("\n1. Nhap so phan tu va gia tri cho mang.\n");
        
        printf("\n2. In ra gia tri trong mang theo dang (arr[0] = 1,...).\n");
        
        printf("\n3. Dem so luong so nguyen to cua mang.\n");
        
        printf("\n4. Tim phan tu nho thu hai trong mang.\n");
        
        printf("\n5. Them mot phan tu vao vi tri ngau nhien trong mang.\n");
        
        printf("\n6. Xoa phan tu tai mot vi tri cu the.\n");

        printf("\n7. Sap xep mang theo thu tu giam dan ( InsertSort ).\n");

        printf("\n8. Tim kiem phan tu trong mang ( Binary Search ).\n");

        printf("\n9. Xoa phan tu trung lap trong mang va hien thi phan tu doc nhat co trong mang.\n");

        printf("\n10. Dao nguoc thu tu cac phan tu trong mang.\n");
        
        printf("\n+++++++++++++++++++++++++++\n");

        printf("\nMoi ban chon chuc nang: ");
        
        scanf("%d", &choices);

        int check = 0;

        switch (choices) 
        {
            case 1:
                
                int n;
                
                printf("\nNhap so luong phan tu cho mang: ");
                
                scanf("%d", &n);
                
                if(n <= 0 || n > MAX_SIZE)
                {
                    printf("\nSo phan tu ban nhap vao khong hop le, vui long nhap tu 1 - %d! \n", MAX_SIZE);
                    
                    break;
                }
                
                for (int i = 0; i < n; ++i) 
                {
                    printf("\nNhap phan tu thu [ %d ]: ", i);
                    
                    scanf("%d", array + i);
                }
                
                SIZE = n;
                
                printf("\nBan da nhap thanh cong %d phan tu vao trong mang!", n);

                check = 1;
                
                break;
            case 2:
                
                if(SIZE == 0)
                {
                    printf("\nMang hien tai dang trong!\n");
                } 
                    else
                    {
                        printf("\nDanh sach cac phan tu trong mang la:\n\n");
                        
                        for (int i = 0; i < SIZE; ++i) 
                        {                            
                            printf(" arr[%d] = %d", i, array[i]);

                            if(i < SIZE - 1)
                                {
                                    printf(",");
                                }
                        }
                    }
                
                printf("\n");

                check = 1;
                
                break;
            
            case 3:
                
                int countIsPrime = 0;

                int flag = 1;

                for(int i = 0; i < SIZE; i++)
                    {
                        if(array[i] < 2)
                            {
                                flag = 0;
                            }
                                else
                                    {
                                        for(int j = 2; i <= sqrt(array[i]); i++)
                                            {
                                                if(array[i] % j == 0)
                                                    {
                                                        flag = 1;

                                                        break;
                                                    }
                                            }
                                    }
                        
                        if(flag)
                            {
                                countIsPrime++;
                            }
                    }

                printf("\nSo luong cac so nguyen to trong mang la: %d", countIsPrime);

                printf("\n\n");

                check = 1;

                break;
            
            case 4:

            int largest_possible = 100;
            
            int smallest = largest_possible;
            
            int second_smallest = largest_possible;
    
            for (int i = 0; i < SIZE; i++) 
                {
                    if (array[i] < smallest) 
                        {
                            second_smallest = smallest;
                            
                            smallest = array[i];
                        } 
                            else if (array[i] > smallest && array[i] < second_smallest) 
                                {
                                    second_smallest = array[i];
                                }
                }

                    if (second_smallest == largest_possible) 
                        {
                            printf("\nTrong mang khong co phan tu nho thu hai ( hai phan tu nho nhat bang nhau )\n");
                        } 
                            else 
                                {
                                    printf("\nSo nho thu hai la: %d\n", second_smallest);
                                }
                
                check = 1;
                
                break;

            case 5:
                
                int addIndex, newValue;
                
                printf("\nNhap gia tri can them vao mang: ");
                
                scanf("%d",&newValue);
                
                printf("\nNhap vi tri can them vao mang: ");
                
                scanf("%d",&addIndex);
                
                if(addIndex < 0)
                {
                    addIndex = 0;
                }
                    else if(addIndex > SIZE)
                        {
                            addIndex = SIZE;
                        }
                
                for(int i = SIZE; i > addIndex; i--)
                    {
                        array[i] = array[i-1];
                    }
                
                array[addIndex] = newValue;
                
                SIZE++;
                
                printf("\nDa them phan tu thanh cong!\n");

                check = 1;
                
                break;
            case 6:
                
                int deleteIndex;

                printf("\nMoi ban nhap vi tri phan tu can xoa: ");
                
                scanf("%d", &deleteIndex);
                
                if(deleteIndex < 0 ||deleteIndex >= SIZE )
                {
                    printf("\nVi tri ban muon xoa phan tu khong hop le!");
                    
                    break;
                }
                
                for (int i = deleteIndex; i < SIZE - 1 ; ++i) 
                {
                    array[i] = array[i + 1];
                }
                
                SIZE--;
                
                printf("\nXoa phan tu thanh cong!");

                check = 1;
                
                break;
                
            case 7:
                
                for(int i = 1; i < SIZE; i++)
                    {
                        int key = array[i];
        
                        int j = i - 1;
        
                        while(j >= 0 && array[j] < key)
                            {
                                array[j + 1] = array[j];
            
                                j = j - 1;
                            }
                        
                        array[j + 1] = key;
                    }

                printf("\nMang sau khi dung InsertionSort sap xep cac phan tu trong mang theo thu tu giam dan: ");

                for(int i = 0; i < SIZE; i++) 
                    {
                        printf("%d ", array[i]);
                    }

                check = 1;
                
                break;
                
            case 8:
                
                int findValue;
    
                printf("\nNhap phan tu can tim kiem trong mang: ");
    
                scanf("%d", &findValue);

                int left = 0, right = SIZE - 1;
    
                int pos = -1;
    
                while (left <= right) 
                    {
                        int m = (left + right) / 2;
        
                        if (array[m] == findValue) 
                            {
                                pos = m;
            
                                right = m - 1; 
                            } 
                                else if (array[m] < findValue) 
                                    {
                                        left = m + 1;
                                    } 
                                        else 
                                            {
                                                right = m - 1;
                                            }
                    }

                    if (pos != -1) 
                        {
                            printf("\nPhan tu %d duoc tim thay tai vi tri %d trong mang.\n\n", findValue, pos);
                        } 
                            else 
                                {
                                    printf("\nPhan tu %d khong co trong mang!\n\n", findValue);
                                }

                check = 1;

                break;

            case 9:                                       
                break;
            
            case 10:
                
                printf("\nPhan tu trong mang sap xep theo thu tu nguoc lai: ");
                
                for(int i = SIZE - 1; i >= 0; i--)
                    {
                        printf("%d ", array[i]);
                    }

                printf("\n\n");

                check = 1;
                                
                break;
            
            default:
                
                printf("\nLua chon ko hop le, vui long nhap lai!");
                
                break;
        }
        
        if(check == 0)
        {
            printf("\nThoat chuong trinh!\n\n");
            
            break;
        }

    }
    
    return 0;
}
