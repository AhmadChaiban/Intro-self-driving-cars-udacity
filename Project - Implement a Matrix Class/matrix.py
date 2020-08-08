import math
from math import sqrt
import numbers

def zeroes(height, width):
		"""
		Creates a matrix of zeroes.
		"""
		g = [[0.0 for _ in range(width)] for __ in range(height)]
		return Matrix(g)

def identity(n):
		"""
		Creates a n x n identity matrix.
		"""
		I = zeroes(n, n)
		for i in range(n):
			I.g[i][i] = 1.0
		return I

class Matrix(object):

	# Constructor
	def __init__(self, grid):
		self.g = grid
		self.h = len(grid)
		self.w = len(grid[0])

	#
	# Primary matrix math methods
	#############################
 
	def determinant(self):
		"""
		Calculates the determinant of a 1x1 or 2x2 matrix.
		"""
		if not self.is_square():
			raise ValueError("Cannot calculate determinant of non-square matrix.")
		if self.h > 2:
			raise NotImplementedError("Calculating determinant not implemented for matrices largerer than 2x2.")
		
		# determinant computation
		if self.h == 1:
			return self.g[0][0]
		elif self.h == 2:
			return (self.g[0][0]*self.g[1][1]) - (self.g[0][1]*self.g[1][0])


	def trace(self):
		"""
		Calculates the trace of a matrix (sum of diagonal entries).
		"""
		if not self.is_square():
			raise ValueError("Cannot calculate the trace of a non-square matrix.")

		total_sum = 0
		for i in range(0, self.h):
			total_sum += self.g[i][i]
		return total_sum

	def inverse(self):
		"""
		Calculates the inverse of a 1x1 or 2x2 Matrix.
		"""
		if not self.is_square():
			raise ValueError("Non-square Matrix does not have an inverse.")
		if self.h > 2:
			raise NotImplementedError("inversion not implemented for matrices larger than 2x2.")

		if self.h == 1:
			return Matrix([[1/self.g[0][0]]])
		else:
			det_factor = 1/self.determinant()
			mat_inverse = [
				[self.g[1][1]*det_factor, -self.g[0][1]*det_factor],
				[-self.g[1][0]*det_factor, self.g[0][0]*det_factor]
			]
			return Matrix(mat_inverse)

	def T(self):
		"""
		Returns a transposed copy of this Matrix.
		"""
		transpose_matrix = []
		for i in range(0, self.w):
			row = []
			for j in range(0, self.h):
				row.append(self.g[j][i])
			transpose_matrix.append(row)
		return Matrix(transpose_matrix)

	def is_square(self):
		return self.h == self.w

	#
	# Begin Operator Overloading
	############################
	def __getitem__(self,idx):
		"""
		Defines the behavior of using square brackets [] on instances
		of this class.

		Example:

		> my_matrix = Matrix([ [1, 2], [3, 4] ])
		> my_matrix[0]
		  [1, 2]

		> my_matrix[0][0]
		  1
		"""
		return self.g[idx]

	def __repr__(self):
		"""
		Defines the behavior of calling print on an instance of this class.
		"""
		s = ""
		for row in self.g:
			s += " ".join(["{} ".format(x) for x in row])
			s += "\n"
		return s

	def __add__(self,other):
		"""
		Defines the behavior of the + operator
		"""
		if self.h != other.h or self.w != other.w:
			raise ValueError

		sum_matrix = []
		for i in range(0, self.h):
			row_sum = []
			for j in range(0, self.w):
				row_sum.append(self.g[i][j] + other.g[i][j])
			sum_matrix.append(row_sum)
		return Matrix(sum_matrix)

	def __neg__(self):
		"""
		Defines the behavior of - operator (NOT subtraction)

		Example:

		> my_matrix = Matrix([ [1, 2], [3, 4] ])
		> negative  = -my_matrix
		> print(negative)
		  -1.0  -2.0
		  -3.0  -4.0
		"""
		negative_matrix = []
		for i in range(0, self.h):
			negative_matrix.append([-1*a for a in self.g[i]])
		return Matrix(negative_matrix)


	def __sub__(self, other):
		"""
		Defines the behavior of - operator (as subtraction)
		"""
		if self.h != other.h or self.w != other.w:
			raise ValueError

		sum_matrix = []
		for i in range(0, self.h):
			row_sum = []
			for j in range(0, self.w):
				row_sum.append(self.g[i][j] - other.g[i][j])
			sum_matrix.append(row_sum)
		return Matrix(sum_matrix)

	def __mul__(self, other):
		"""
		Defines the behavior of * operator (matrix multiplication)
		"""
		mult_matrix = []
		for rowA in self.g:
			mult_row = []
			for rowB in other.T():
				mult_row.append(sum([a*b for a,b in zip(rowA,rowB)]))
			mult_matrix.append(mult_row)
		return Matrix(mult_matrix)

	def __rmul__(self, other):
		"""
		Called when the thing on the left of the * is not a matrix.

		Example:

		> identity = Matrix([ [1,0], [0,1] ])
		> doubled  = 2 * identity
		> print(doubled)
		  2.0  0.0
		  0.0  2.0
		"""
		if isinstance(other, numbers.Number):
			final_matrix = []
			for i in range(self.h):
				row = []
				for j in range(self.w):
					row.append(other * self.g[i][j])
				final_matrix.append(row)
			return Matrix(final_matrix)

	











