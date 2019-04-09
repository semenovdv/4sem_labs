#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

int main(){

    long long n = 0;
    long long m = 0;
    
    std::cin >> n >> m;
    std::vector<std::vector<long long>> vect(n, std::vector<long long>(m));
    std::vector<std::vector<long long>> res(n, std::vector<long long>(m));
    std::vector<std::vector<std::pair<long long, long long>>> matr(n, std::vector<std::pair<long long, long long>>(m));
    
    // reading to vector

    long long k = 0;
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < m; j++){
            std::cin >> k;
            vect[i][j] = k;
        }
    }

    res = vect;

    for(long long i = 1; i < n; i++){
        // пограничное значние
        if (res[i-1][0] < res[i-1][1]){
            res[i][0] += res[i-1][0];
            matr[i][0] = std::pair<long long, long long>(i-1, 0);

        } else {
            res[i][0] += res[i-1][1];
            matr[i][0] = std::pair<long long, long long>(i-1, 1);
        }

        for(long long j = 1; j < m-1; j++){
            if (res[i-1][j] < res[i-1][j+1]){
                if (res[i-1][j-1] < res[i-1][j]){
                    res[i][j] += res[i-1][j-1];
                    matr[i][j] = std::pair<long long, long long>(i-1,j-1);
                } else {
                    res[i][j] += res[i-1][j];
                    matr[i][j] = std::pair<long long, long long>(i-1,j);
                }
            } else {
                if (res[i-1][j-1] < res[i-1][j+1]){
                    res[i][j] += res[i-1][j-1];
                    matr[i][j] = std::pair<long long, long long>(i-1,j-1);
                } else {
                    res[i][j] += res[i-1][j+1];
                    matr[i][j] = std::pair<long long, long long>(i-1,j+1);
                }
            }

        }

        // пограничное значение
        if (res[i-1][m-2] < res[i-1][m-1]){
            res[i][m-1] += res[i-1][m-2];
            matr[i][m-1] = std::pair<long long, long long>(i-1, m-2);

        } else {
            res[i][m-1] += res[i-1][m-1];
            matr[i][m-1] = std::pair<long long, long long>(i-1, m-1);
        } 
        
        // отладочный вывод
        /*
        std::cout << "-------------" << std::endl;
        std::cout << n << " " << m << std::endl;
        for (int i = 0; i < n; i++){
            for( int j = 0; j < m; j++){
                std::cout << matr[i][j].first << "," << matr[i][j].second << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "-------------" << std::endl;
        */
    }

    long long minzn = res[n-1][0];
    long long minind = 0;
    for(long long i = 0; i < m; i++)
        if (res[n-1][i] < minzn){
            minzn = res[n-1][i];
            minind = i;
        }

    std::cout << minzn << std::endl;// << " " << minind<<  std::endl;std

    /*
     std::cout << "-------------" << std::endl;
        std::cout << n << " " << m << std::endl;
        for (int i = 0; i < n; i++){
            for( int j = 0; j < m; j++){
                std::cout << matr[i][j].first << "," << matr[i][j].second << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "-------------" << std::endl;
    */
    std::stack<std::pair<long long, long long>> st;
    long long i1 = n-1;
    long long i2 = minind;
    st.push(std::pair<long long, long long>(i1+1, i2+1));
    //std::cout << i1 << "-" << i2 << std::endl;
    //std::cout << "matr42 " << matr[4][2].first << " " << matr[4][2].second << std::endl;

    for (long long i = 0; i < n-1; i++){
        long long i1k = i1;
        long long i2k = i2;
        
        i1 = matr[i1k][i2k].first ;
        //std::cout << "i1 = " << i1 << std::endl;
        i2 = matr[i1k][i2k].second;
        //std::cout << "i2 = " << i2 << std::endl;
        //std::cout << i1 << "-" << i2 << std::endl;
        st.push(std::pair<long long, long long>(i1+1, i2+1));
    }


    //st.push(std::pair<int, int>(i1, i2));

    

    while(!st.empty()) {
        std::cout << "(" << st.top().first << ","  << st.top().second  <<  ")";
        st.pop();
        if (st.size() != 0) std::cout <<" ";
    }
    std::cout << std::endl;
    return 0;
}