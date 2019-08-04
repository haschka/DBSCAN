/*! \brief Structure for a n dimenstional dataset composed of
 *         non missing floating point values.
 */
typedef struct {
  float** values;
  int n_values; /*!< number of samples in the dataset*/
  int n_dimensions; /*!< number of features*/
} dataset;

/*! \brief Structure storing a single cluster to be found by
 *         clustering algorithms
 *         such as dbscan.
 */
typedef struct {
  int * members;  /*!< integer containing the number of each sample that is
		   *   part of this cluster */
  int n_members;  /*!< number of samples represented in this cluster */
  int id;         /*!< unique cluster id in a set of clusters */
} cluster;

/*! \brief Structure storing multiple clusters of a dataset to be found by
 *         clustering algorithms such as dbscan.
 */
typedef struct {
  int n_clusters; /*!< number of clusters to be contained in this set */
  cluster* clusters; /*!< the clusters contained within this set */
} split_set;

/*! \brief Structure storing close or neighbor features of a
 *         feature and used for
 *         the internal workings of dbscan.
 */
typedef struct {
  int * members; /*!< the features in this neighbourhood */
  int n_members; /*!< number of features in this neighborhood */
} neighbors;

split_set dbscan(dataset ds, float epsilon, int minpts);
