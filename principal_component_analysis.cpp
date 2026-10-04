// principal_component_analysis.cpp
//
// This program performs Principal Component Analysis (PCA) on a dataset.
//
// Goal:
//   Find a new set of orthogonal axes, called principal components, that capture
//   as much of the variation in the original data as possible.
//
//   PCA can then reduce the dimensionality of the dataset by retaining only the
//   first k principal components, where k < m.
//
// Let:
//   X = original data matrix
//   n = number of samples (rows)
//   m = number of features (columns)
//
// Therefore:
//   X has shape n x m
//
//
// ============================================================================
// Step 1: Centre the data
// ============================================================================
//
// PCA measures variance around the mean, so each feature must first be centred.
//
// For each feature j, calculate its mean:
//
//   mean_j = (1 / n) * sum(X_ij),  for i = 1,...,n
//
// Collect the feature means into a mean vector:
//
//   u = [mean_1, mean_2, ..., mean_m]        shape: 1 x m
//
// Subtract the corresponding feature mean from every observation:
//
//   Xc_ij = X_ij - mean_j
//
// Or in matrix notation:
//
//   Xc = X - u
//
// where u is broadcast/subtracted from every row of X.
//
// After centering, every column of Xc should have mean approximately 0.
//
// Result:
//
//   Xc has shape n x m
//
//
// ============================================================================
// Step 2: Compute the covariance matrix
// ============================================================================
//
// The covariance matrix describes:
//   1. How much each feature varies.
//   2. How pairs of features vary together.
//
// Using the centred data:
//
//   C = (1 / (n - 1)) * Xc^T * Xc
//
// Shape check:
//
//   Xc^T : m x n
//   Xc   : n x m
//
// Therefore:
//
//   (m x n) * (n x m) = m x m
//
// so:
//
//   C has shape m x m
//
// The diagonal entries contain feature variances:
//
//   C_jj = Var(feature_j)
//
// The off-diagonal entries contain covariance between features:
//
//   C_jk = Cov(feature_j, feature_k)
//
// Since:
//
//   Cov(X_j, X_k) = Cov(X_k, X_j)
//
// the covariance matrix is symmetric:
//
//   C^T = C
//
// Example for two features:
//
//       [ Var(x1)      Cov(x1,x2) ]
//   C = [                         ]
//       [ Cov(x1,x2)   Var(x2)   ]
//
//
// ============================================================================
// Step 3: Find the eigenvalues and eigenvectors of the covariance matrix
// ============================================================================
//
// PCA looks for directions through the data along which variance is maximized.
//
// These directions are given by the eigenvectors of the covariance matrix.
//
// Solve:
//
//   C * v = lambda * v
//
// where:
//
//   C      = covariance matrix                         shape: m x m
//   v      = eigenvector                              shape: m x 1
//   lambda = corresponding eigenvalue                 scalar
//
// Interpretation:
//
//   eigenvector v     -> direction of a principal component
//   eigenvalue lambda -> variance captured along that direction
//
// An eigenvector is a special direction that, when transformed by C,
// keeps the same direction and is only scaled by lambda.
//
// For a 2 x 2 covariance matrix, eigenvalues can be found from:
//
//   det(C - lambda * I) = 0
//
// If:
//
//       [ a  b ]
//   C = [      ]
//       [ c  d ]
//
// then:
//
//   det(C - lambda * I) = 0
//
// becomes:
//
//   lambda^2 - (a + d)lambda + (ad - bc) = 0
//
// or equivalently:
//
//   lambda^2 - trace(C)lambda + det(C) = 0
//
// The two eigenvalues can therefore be found using the quadratic formula.
//
// Once an eigenvalue is known, solve:
//
//   (C - lambda * I)v = 0
//
// to find its corresponding eigenvector.
//
// Finally, normalize each eigenvector so that:
//
//   ||v|| = 1
//
//
// ============================================================================
// Step 4: Sort eigenvalues and eigenvectors
// ============================================================================
//
// Larger eigenvalues correspond to directions containing more variance.
//
// Sort the eigenvalue/eigenvector pairs in descending eigenvalue order:
//
//   lambda_1 >= lambda_2 >= ... >= lambda_m
//
// Their corresponding eigenvectors then define:
//
//   PC1 = v_1
//   PC2 = v_2
//   ...
//   PCm = v_m
//
// PC1 captures the greatest possible variance.
// PC2 captures the greatest remaining variance while being orthogonal to PC1.
// Each subsequent component is orthogonal to the previous components.
//
// The proportion of total variance explained by component i is:
//
//                         lambda_i
//   explained_variance = ----------------
//                        sum(lambda_j)
//
// Therefore:
//
//   explained_variance_i = lambda_i / (lambda_1 + ... + lambda_m)
//
// This can be used to decide how many principal components should be retained.
//
//
// ============================================================================
// Step 5: Select the top k principal components
// ============================================================================
//
// Choose k, where:
//
//   1 <= k <= m
//
// Construct V_k by placing the eigenvectors associated with the k largest
// eigenvalues into columns:
//
//   V_k = [v_1, v_2, ..., v_k]
//
// Since every eigenvector contains m elements:
//
//   V_k has shape m x k
//
//
// ============================================================================
// Step 6: Project the centred data onto the new PCA axes
// ============================================================================
//
// Transform the original centred observations into principal-component
// coordinates:
//
//   Z = Xc * V_k
//
// Shape check:
//
//   Xc  : n x m
//   V_k : m x k
//
// Therefore:
//
//   (n x m) * (m x k) = n x k
//
// so:
//
//   Z has shape n x k
//
// Each row still represents the same original observation, but its columns
// now represent principal-component coordinates instead of original features.
//
// For example, reducing:
//
//   [x1, x2]
//
// to one principal component produces:
//
//   [PC1]
//
// where for observation i:
//
//   PC1_i = Xc_i dot v_1
//
//
// ============================================================================
// Summary
// ============================================================================
//
//   Original data:
//       X                              n x m
//
//              |
//              v
//
//   1. Calculate feature means:
//       u                              1 x m
//
//              |
//              v
//
//   2. Centre data:
//       Xc = X - u                    n x m
//
//              |
//              v
//
//   3. Calculate covariance:
//       C = Xc^T * Xc / (n - 1)       m x m
//
//              |
//              v
//
//   4. Find eigenvalues/eigenvectors:
//       C * v = lambda * v
//
//              |
//              v
//
//   5. Sort by descending eigenvalue:
//       lambda_1 >= lambda_2 >= ...
//
//              |
//              v
//
//   6. Keep top k eigenvectors:
//       V_k                            m x k
//
//              |
//              v
//
//   7. Project centred data:
//       Z = Xc * V_k                  n x k
//
//
// PCA pipeline:
//
//   X -> centre -> covariance -> eigendecomposition -> sort -> select -> project
//
// ============================================================================