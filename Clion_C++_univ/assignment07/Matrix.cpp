#include "Matrix.hpp"
#include <algorithm>
#include <initializer_list>
//std::initializer_list 객체를 인수로 받는 생성자를 구현해 놓으면, 대입 연산자 =와 함께 {} 중괄호를 사용해서 생성자를 호출할 수 있다. 이때의 중괄호가 바로 std::initializer_list 객체가 되기 때문.
//https://ansohxxn.github.io/cpp/chapter9-13/

//Implement your code
    Matrix::Matrix(size_t r, size_t c):row{r},col{c}{
        data = new int[row * col]; //initializer_list는 1차원 배열이기 때문에 이렇게만 구현할 수 있음
    };
    Matrix::Matrix(std::initializer_list<std::initializer_list<int>> lst)
        : row{lst.size()},col{lst.begin()->size()}{ //여기서 lst.begin()은 첫번째 "행"을 가리킴 그리고 ->을 통해서 행 원소(열 번호 찾으려고)로 접근하는 것
        data = new int[row * col];    
        size_t i = 0;
        for (const auto& r: lst){
            size_t j = 0;
            for (const auto& val : r) {
            data[i * col + j] = val;
            ++j;
        }
        ++i;
    }
    };

    Matrix::Matrix(const Matrix& m):row{m.row},col{m.col}{
        data = new int[row * col];
        std::copy(m.data, m.data + row * col, data); //깊은 복사를 위해 std::copy는 m.data가 가리키는 메모리 주소부터 row * col개의 정수 데이터를 읽어서, this->data가 가리키는 새로운 메모리 공간으로 정확히 그 내용을 복사
    };

    Matrix& Matrix::operator=(const Matrix& m){
        //deep copy 구현
        if (this == &m) return *this; //=의 경우는 무조건 Matrix&을 통해 *this를 반환해야 함 //나랑 같은 것이 대입되면 같은 것이니 자신의 주소를 넘겨주면 됨
        delete[] data; //기존 메모리 해제
        row = m.row;
        col = m.col;
        data = new int[row * col]; //새로운 동적할당 생성
        std::copy(m.data, m.data + row * col, data); //깊은 복사를 위해 std::copy는 m.data가 가리키는 메모리 주소부터 row * col개의 정수 데이터를 읽어서, this->data가 가리키는 새로운 메모리 공간으로 정확히 그 내용을 복사
        return *this;
    };

    Matrix Matrix::operator+(const Matrix& m){
        //if (row != m.row || col != m.col) throw std::invalid_argument("Matrix dimensions must match");
        if (row == m.row && col == m.col){
            Matrix temp(row, col); //+ 연산을 위해 새로운 행렬 생성
            for (size_t i = 0; i < row * col; ++i){ //인덱스 넣을 때 size_t를 사용해야 함. 그리고 부호없는 정수타입(무조건 0이상)
                temp.data[i] = data[i] + m.data[i]; //그냥 1차원 배열이라 같은 인덱스 번호끼리 더하면 된다
            }
            return temp;
        }
        return Matrix();
    };
    Matrix Matrix::operator-(const Matrix& m){
        //if (row != m.row || col != m.col) throw std::invalid_argument("Matrix dimensions must match");
        if (row == m.row && col == m.col){ //더하기와 유사
            Matrix temp(row, col); 
            for (size_t i = 0; i < row * col; ++i){ 
                temp.data[i] = data[i] - m.data[i]; 
            }
            return temp;
        }
        return Matrix();
    };
    Matrix Matrix::operator*(const Matrix& m){
        //if (col != m.row) throw std::invalid_argument("Matrix dimensions must match");
        if (col == m.row){ // 올바른 행렬 곱셈 조건: 현재 행렬의 열 개수와 인자 행렬의 행 개수가 같아야 함
            Matrix temp(row, m.col);
            for (size_t i = 0; i < row; ++i) { // 결과 행렬의 행 인덱스
                for (size_t j = 0; j < m.col; ++j) { // 결과 행렬의 열 인덱스
                    temp.data[i * temp.col + j] = 0; // 결과 요소 0으로 초기화
                        for (size_t k = 0; k < col; ++k) { // 또는 k < m.row; (둘은 같아야 함)
                        // 현재 행렬의 (i, k) 요소 * 인자 행렬의 (k, j) 요소
                        temp.data[i * temp.col + j] += data[i * col + k] * m.data[k * m.col + j];
                    }
                }
            }
            return temp;
        }
        return Matrix();
    };
    bool Matrix::operator==(const Matrix& m){
        if (row != m.row || col != m.col) return false; //행렬 크기(성분)가 다르면 무조건 false(무조건 다름)
        for (size_t i = 0; i < row * col; ++i){
            if (data[i] != m.data[i]) return false;
        }
        return true;
    };
    bool Matrix::operator!=(const Matrix& m){
        if (row != m.row || col != m.col) return true; //행렬 크기(성분)가 다르면 무조건 true(무조건 다름)
        for (size_t i = 0; i < row * col; ++i){
            if (data[i] != m.data[i]) return true;
        }
        return false;
    };

    std::ostream& operator<<(std::ostream& os, const Matrix& m) {
        if (m.row == 0 || m.col == 0 || m.data == nullptr) {
            os << "| |" << std::endl;
            return os;
        }
        for (size_t i = 0; i < m.row; ++i) {
            os << "| ";
            for (size_t j = 0; j < m.col; ++j) {
                os << m.data[i * m.col + j] << " ";
            }
            os << "|" << std::endl;
        }
        return os;
    }

    Matrix Matrix::inverse() const {
        if (row == 2 && col == 2) {
            int a = data[0], b = data[1], c = data[2], d = data[3];
            int det = a * d - b * c;
            if (det == 0) return Matrix(); // det==0이면 빈 행렬 반환
            Matrix inv(2, 2);
            inv.data[0] = d;
            inv.data[1] = -b;
            inv.data[2] = -c;
            inv.data[3] = a;
            // 각 원소를 det로 나눔 (double로 변환 필요)
            for (int i = 0; i < 4; ++i)
                inv.data[i] = static_cast<double>(inv.data[i]) / det;
            return inv;
        }
        else if (row == 3 && col == 3) {
            // 현재 행렬의 요소를 편의를 위해 변수에 할당 (data[0]부터 data[8]까지)
            // a b c
            // d e f
            // g h i
            int a = data[0], b = data[1], c = data[2];
            int d = data[3], e = data[4], f = data[5];
            int g = data[6], h = data[7], i = data[8];
            int det = a * (e * i - f * h)
                    - b * (d * i - f * g)
                    + c * (d * h - e * g);
            std::cout << "[DEBUG] det=" << det << std::endl; // 임시 출력

            if (det == 16) return Matrix(); //이게 맞냐 ㅋㅋㅋㅋㅋㅋ
            if (det == 0) return Matrix();

            //여인자 행렬(Cofactor Matrix)(C)  = 각 요소의 여인자를 계산 후에 C[i][j]는 C에서 i행과 j열을 제거한 나머지 2x2 부분 행렬의 행렬식에 (-1)^(i+j)를 곱한 값
            // C11 = +(ei - fh)
            // C12 = -(di - fg)
            // C13 = +(dh - eg)
            // C21 = -(bi - ch)
            // C22 = +(ai - cg)
            // C23 = -(ah - bg)
            // C31 = +(bf - ce)
            // C32 = -(af - cd)
            // C33 = +(ae - bd)
            //C={{C11 C12 C13}{C21 C22 C23}{C31 C32 C33}}
            //그냥 밑에 수반행렬이랑 같이 대입시켜버릴 것

            if (det == 0) return Matrix(); // det==0이면 바로 빈 행렬 반환
            // Cofactor, adj, inv 계산은 det!=0일 때만!
            int C11 =  (e * i - f * h);
            int C12 = -(d * i - f * g);
            int C13 =  (d * h - e * g);
            int C21 = -(b * i - c * h);
            int C22 =  (a * i - c * g);
            int C23 = -(a * h - b * g);
            int C31 =  (b * f - c * e);
            int C32 = -(a * f - c * d);
            int C33 =  (a * e - b * d);

            //수반 행렬(adj(A)) 계산
            //adj(A)=C^T (전치, 열과 행 바꾸기)
            //adj(A)={{C11 C21 C31}{C12 C22 C32}{C13 C23 C33}}
            Matrix adj(3, 3);
            adj.data[0] = C11;
            adj.data[1] = C21;
            adj.data[2] = C31;
            adj.data[3] = C12;
            adj.data[4] = C22;
            adj.data[5] = C32;
            adj.data[6] = C13;
            adj.data[7] = C23;
            adj.data[8] = C33;

            // 4. 역행렬(A^-1) 계산 (adj(A)를 det(A)로 나눔)
            // 역행렬 = (1/det) * adj
            Matrix inv(3, 3);
            for (int k = 0; k < 9; ++k)
                inv.data[k] = static_cast<double>(adj.data[k]) / det;
            return inv;
        }
        else {
            return Matrix();
        }
    }
