# DBSCAN
A vectorized (AVX, SSE and scalar) implementation of DBSCAN.

Please read the LICNESE file before using this implementation.

* Usage
you need to shape your data so that it fits into the dataset structure
as shown in dbscan.h:
```
typedef struct {
  float** values;
  int n_values; /*!< number of samples in the dataset*/
  int n_dimensions; /*!< number of features*/
} dataset;
```
where n_dimensions are the number of features that your dataset has,
and n_values is the number of values. The two dimensional array of values
should be organized in such a way that the first index is the
feature index and the second index is the sample index, hence that:
```
values[i][k]
```
is the k th sample of the feature i.

When allocating the memory make sure that the arrays holding the samples,
[k] is 32 bytes aligned if your architecture supports AVX and at
least 16 bytes alined if your architecture supports SSE.
This can be achieved by allocating your memory with
```
posix_memalign(void **memptr, size_t alignment, size_t size);
```
instead of calling malloc.

once you have established your dataset you can call the function
```
split_set dbscan(dataset ds, float epsilon, int minpts);
```
where ds is your dataset to be clustered, epsilon is the dbscan
epsilon radius and minpts is the number of points that shall are sufficient
within the radius epsilon to form a cluster

You then obtain a split_set structure that holds your clusters
```
typedef struct {
  int n_clusters; /*!< number of clusters to be contained in this set */
  cluster* clusters; /*!< the clusters contained within this set */
} split_set;
```
where each cluster in the clusters array is built upon the following structure:
```
typedef struct {
  int * members;  /*!< integer containing the number of each sample that is
		   *   part of this cluster */
  int n_members;  /*!< number of samples represented in this cluster */
  int id;         /*!< unique cluster id in a set of clusters */
} cluster;
```
Here the members array contains the array indexes of the samples that are
part of the cluster, hence if we go back to our dataset structure where
we said that
```
values[i][k]
```
are the values of our dataset, then this members array contains the k index
of the sample that is part of this cluster.


