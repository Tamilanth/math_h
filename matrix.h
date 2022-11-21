#include <vector>

namespace matrix
{

  class sq_matrix_n
  {

    float dt = 0;
    std::vector<std::vector<float>> _matrix_;
  public:
    sq_matrix_n (std::vector<std::vector<float>> &mat)
    {
      _matrix_ = mat;
    }

    /*sq_matrix_n(int rows, int cols)
    {

      for(int i = 0; i < rows;i++)
	{
	  for(int j = 0; j < cols; j++)
	    {
	      

    */
    

    sq_matrix_n()
    {
      std::cout << "Error! Couldn't declare a object of type \"sq_matrix_n\" without arguments " << std::endl;
      std::exit(-1);
    }

  };

  class sq_matrix_2
  {
    float dt = 0;
    std::vector<std::vector<float>> _matrix_ = {{0,0},{0,0}};
  public:
    sq_matrix_2 (std::vector<std::vector<float>> &mat)
    {
        _matrix_ = mat;
    }

    ~sq_matrix_2()
    {
      print();
    }

    sq_matrix_2(){}

    sq_matrix_2 operator+(sq_matrix_2 &mat2)
    {
      sq_matrix_2 added;
      for(int i = 0; i < 2; i++)
	{
	  for(int j = 0; j < 2;j++)
	    added._matrix_[i][j] = this->_matrix_[i][j] + mat2._matrix_[i][j];
	}
      return added;
    }

    bool is_invertible()
    {
	if(det() != 0)
	  {
	  return true;
	  }
	else
	  {
	    std::cout << "Error:The following matrix is not invertible\n\n" << std::endl;
	    return false;
	  }
    }

    void get()
    {
      for(int o = 0; o < 2; o++)
	{
	  for(int p = 0; p < 2;p++)
	    std::cin >> _matrix_[o][p];
	}
    }

    void print()
    {
      for(auto rows: _matrix_)
	{
	  for(auto eles: rows)
	    std::cout << eles << "  ";
	  std::cout << std::endl;
	}
      std::cout << std::endl;
    }

    void adj()
    {
      std::cout << "Finding the adjoint of the martix:\n"; 
        auto temp = _matrix_[0][0];
        _matrix_[0][0] = _matrix_[1][1];
        _matrix_[1][1] = temp;
        temp = _matrix_[0][1];
        _matrix_[0][1] = -_matrix_[1][0];
        _matrix_[1][0] = -temp;
    }

  void transpose()
  {
    std::cout << "Transposing the given matrix\n";

    auto temp = _matrix_[1][0];
    _matrix_[1][0] = _matrix_[0][1];
    _matrix_[0][1] = temp;
  }

    friend void print(matrix::sq_matrix_2 vec);

    float det()
    {
      std::cout << "Finding the determinent of the matrix\n";
      dt = _matrix_[0][0] * _matrix_[1][1] - _matrix_[0][1] * _matrix_[1][0];
      return dt;

    }
    
    void inverse()
    {
      std::cout << "Finding the inverse of the matrix is\n";
      det();
      adj();
      transpose();
      for(int i = 0; i < 2; i++)
	for(int j = 0; j < 2; j++)
	  _matrix_[i][j] = 1/dt * _matrix_[i][j];
    }
};

void print(std::vector<std::vector<float>> vec)
{
  for(auto i: vec)
    {
      for(auto u: i)
	std::cout << u<< "  ";
      std::cout << std::endl;
    }
  std::cout << std::endl;
}

void print(matrix::sq_matrix_2 vec)
{
  for(auto i: vec._matrix_)
    {
      for(auto u: i)
	std::cout << u<< "  ";
      std::cout << std::endl;
    }
  std::cout << std::endl;
}
}

/*
std::vector<std::vector<int>> multipy(std::vector<std::vector<int>> A, std::vector<std::vector<int>> B)
{
  std::vector<std::vector<int>> prod;
  //if(A[0].size == B[0][1].size + B[0)
  for(int rows = 0; rows < A.size();rows++)
    {
      for(int eles = 0; eles < A[rows].size; eles++)
	prod[rows].push_back();
	  }
}
*/
