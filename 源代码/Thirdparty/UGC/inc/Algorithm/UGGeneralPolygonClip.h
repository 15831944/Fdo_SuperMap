//-------------------------------------------------------------------------------------
// �ļ�����			UGGeneralPolygonClip.h
// ��  ����			UGGeneralPolygonClip
// ��  �ࣺ			
// ��  �ࣺ			
// ����˵����		����βü�
// ����˵����		
// ����˵��
//    2007.09.24 guohui	��ͷ�ļ�������ϸע�ͣ���һЩ����ע�ͽ��м򻯣��Ը�ʽ��������// 
//    2007.10.09 guohui	Ϊ�˽���ڴ�й¶�����⣬������ new XX ��Ϊ new XX[1].
//						 �� FREE(p){free(p); (p)= NULL;}��Ϊ FREE(p){delete [](p); (p)= NULL;}
//-------------------------------------------------------------------------------------

#ifndef UGGeneralPolygonClip_H
#define UGGeneralPolygonClip_H

#include "Algorithm/UGPoint2D.h"

namespace UGC {
	 
//#define GPC_EPSILON (1.0e-8)
#define GPC_EPSILON (1.0e-11)
#define GPC_VERSION_231
#ifdef GPC_VERSION_231
	#define GPC_VERSION "2.31"
#else
	#define CPC_VERSION "2.22"
#endif

typedef UGPoint2D gpc_vertex;					//	use UGPoint2D as struct{ UGdouble x,UGdouble y }

//! \brief GPC�������Ķ���
typedef struct									//	Vertex list structure 
{
  UGint                 num_vertices;			//  Number of vertices in list 
  gpc_vertex            *vertex		;			//  Vertex array pointer  
} gpc_list;

//! \brief ��״̬
//This struct is only used in version 2.31
typedef enum									//	Edge bundle state
{
  UNBUNDLED,									//	Isolated edge not within a bundle
  BUNDLE_HEAD,									//	Bundle head node 
  BUNDLE_TAIL									//	Passive bundle tail node
} bundle_state;						

#ifdef GPC_VERSION_231
	//This is version 2.31
	//! \brief ����εĴ洢�ṹ
  //{{ by guohui & qiuli 2007.10.10
//	typedef struct								//	Polygon set structure
//	{
//	  UGint				num_contours;			//	Number of contours in polygon
//	  UGint             *hole		;		    //	Hole / external contour flags
//	  gpc_list			*contour	;			//	Contour array pointer
//	} gpc_polygon;
	typedef struct Taggpc_polygon				//	Polygon set structure
	{
	  UGint				num_contours;			//	Number of contours in polygon
	  UGint             *hole		;		    //	Hole / external contour flags
	  gpc_list			*contour	;			//	Contour array pointer
	  Taggpc_polygon()
	  {
		  num_contours = 0 ; 
		  hole = NULL;
		  contour = NULL;
	  };
	} gpc_polygon;
  //}} by guohui & qiuli 2007.10.10
#else
#ifdef GPC_VERSION_2.22
	//! \brief ����εĴ洢�ṹ
	typedef struct								// Polygon set structure             
	{
	  UGint             num_contours;			// Number of contours in polygon     
	  gpc_list			*contour;				// Contour array pointer             
	} gpc_polygon;
#endif 	//#ifdef GPC_VERSION_2.22
#endif

typedef struct									// Tristrip set structure            
{
	UGint					num_strips	;		// Number of tristrips               
	gpc_list				*strip		;		// Tristrip array pointer            
} gpc_tristrip;
/*
===========================================================================
                            Private Data Types
===========================================================================
*/

typedef enum                        // Edge intersection classes         
{
  NUL,                              // Empty non-intersection            
  EMX,                              // External maximum                  
  ELI,                              // External left intermediate        
  TED,                              // Top edge                          
  ERI,                              // External right intermediate       
  RED,                              // Right edge                        
  IMM,                              // Internal maximum and minimum      
  IMN,                              // Internal minimum                  
  EMN,                              // External minimum                  
  EMM,                              // External maximum and minimum      
  LED,                              // Left edge                         
  ILI,                              // Internal left intermediate        
  BED,                              // Bottom edge                       
  IRI,                              // Internal right intermediate       
  IMX,                              // Internal maximum                  
  FUL                               // Full non-intersection             
} vertex_type;

typedef enum                        // Horizontal edge states            
{
  NH,                               // No horizontal edge 
  BH,                               // Bottom horizontal edge     
  TH                                // Top horizontal edge   
} h_state;

typedef struct v_shape              // Internal vertex list datatype     
{
  UGdouble              x;          // X coordinate component            
  UGdouble              y;          // Y coordinate component            
  struct v_shape     *next;         // Pointer to next vertex in list    
} vertex_node;

#ifdef GPC_VERSION_231

	typedef struct p_shape              /* Internal contour / tristrip type  */
	{
	  UGint                 active;       /* Active flag / vertex count        */
	  UGint                 hole;         /* Hole / external contour flag      */
	  vertex_node        *v[2];         /* Left and right vertex list ptrs   */
	  struct p_shape     *next;         /* Pointer to next polygon contour   */
	  struct p_shape     *proxy;        /* Pointer to actual structure used  */
	} polygon_node;

	typedef struct edge_shape
	{
	  gpc_vertex          vertex;       /* Piggy-backed contour vertex data  */
	  gpc_vertex          bot;          /* Edge lower (x, y) coordinate      */
	  gpc_vertex          top;          /* Edge upper (x, y) coordinate      */
	  UGdouble              xb;           /* Scanbeam bottom x coordinate      */
	  UGdouble              xt;           /* Scanbeam top x coordinate         */
	  UGdouble              dx;           /* Change in x for a unit y increase */
	  UGint                 type;         /* Clip / subject edge flag          */
	  UGint                 bundle[2][2]; /* Bundle edge flags                 */
	  UGint                 bside[2];     /* Bundle left / right indicators    */
	  bundle_state        bstate[2];    /* Edge bundle state                 */
	  polygon_node       *outp[2];      /* Output polygon / tristrip pointer */
	  struct edge_shape  *prev;         /* Previous edge in the AET          */
	  struct edge_shape  *next;         /* Next edge in the AET              */
	  struct edge_shape  *pred;         /* Edge connected at the lower end   */
	  struct edge_shape  *succ;         /* Edge connected at the upper end   */
	  struct edge_shape  *next_bound;   /* Pointer to next bound in LMT      */
	} edge_node;

	typedef struct st_shape             /* Sorted edge table                 */
	{
	  edge_node          *edge;         /* Pointer to AET edge               */
	  UGdouble              xb;           /* Scanbeam bottom x coordinate      */
	  UGdouble              xt;           /* Scanbeam top x coordinate         */
	  UGdouble              dx;           /* Change in x for a unit y increase */
	  struct st_shape    *prev;         /* Previous edge in sorted list      */
	} st_node;

#else //Version 2.22
#ifdef GPC_VERSION_2.22
	typedef struct p_shape              // Internal polygon / tristrip type  
	{
	  UGint                 active;       // Active flag / vertex count        
	  vertex_node       **proxy;        // Pointer to actual v[] list in use 
	  vertex_node        *v[2];         // Left and right vertex list ptrs   
	  struct p_shape     *next;         // Pointer to next polygon contour   
	} polygon_node;

	typedef struct edge_shape
	{
		UGPoint2D          vertex;        // Piggy-backed contour vertex data  
		UGPoint2D          bot;           // Edge lower (x, y) coordinate      
		UGPoint2D          top;           // Edge upper (x, y) coordinate      
		UGdouble              x;             // Line x coordinate for current y   
		UGdouble              delx;          // Change in x for a unit y increase 
		UGint                 type;          // Clip / subject edge flag          
		UGint                 head;          // Head of bundle flag               
		UGint                 bundle[2][2];  // Bundle edge flags                 
		UGint                 bside[2];      // Bundle left / right indicators    
		polygon_node        *outp;         // Output polygon / tristrip pointer 
		struct edge_shape   *prev;         // Previous edge in the AET          
		struct edge_shape   *next;         // Next edge in the AET              
		struct edge_shape   *pred;         // Edge connected at the lower end   
		struct edge_shape   *succ;         // Edge connected at the upper end   
		struct edge_shape   *next_bound;   // Pointer to next bound in LMT      
	} edge_node;

	typedef struct st_shape             // Sorted edge table       
	{
	  edge_node          *e;            // Pointer to AET edge               
	  UGdouble              xtop;         // X coordinate at top of scanbeam   
	  struct st_shape    *prev;         // Previous edge in sorted list      
	} st_node;
#endif //#ifdef GPC_VERSION_2.22
#endif

typedef struct lmt_shape            // Local minima table                
{
  UGdouble              y;            // Y coordinate at local minimum     
  edge_node          *first_bound;  // Pointer to bound list             
  struct lmt_shape   *next;         // Pointer to next local minimum     
} lmt_node;

typedef struct sbt_t_shape          // Scanbeam tree                     
{
  UGdouble              y;            // Scanbeam node y value             
  struct sbt_t_shape *less;         // Pointer to nodes with lower y     
  struct sbt_t_shape *more;         // Pointer to nodes with higher y    
} sb_tree;

typedef struct it_shape             // Intersection table                
{
  edge_node          *ie[2];        // Intersecting edge (bundle) pair   
  UGPoint2D           point;         // Point of intersection             
  struct it_shape    *next;         // The next intersection table node  
} it_node;


//new struct in version 2.31
typedef struct bbox_shape           /* Contour axis-aligned bounding box */
{
  UGdouble             xmin;          /* Minimum x coordinate              */
  UGdouble             ymin;          /* Minimum y coordinate              */
  UGdouble             xmax;          /* Maximum x coordinate              */
  UGdouble             ymax;          /* Maximum y coordinate              */
} bbox;


class ALGORITHM_API UGGeneralPolygonClip   //ʱ���������������,�����2.31�汾
{
public:
	UGGeneralPolygonClip();
	virtual ~UGGeneralPolygonClip();
public:
	enum                        // Set operation type                
	{
	  Difference=0,             // Difference                        
	  Intersect=1,              // Intersection                      
	  Union=2,                  // Union 
	  Xor=3                     // Exclusive or   
	} ;
	
protected:
	static void  reset_it(it_node **it);
	static void  reset_lmt(lmt_node  **lmt);
	static void  insert_bound(edge_node **b, edge_node *e);
	static edge_node **bound_list(lmt_node **lmt, UGdouble y);
	static void  add_to_sbtree(UGint *entries, sb_tree **sbtree, UGdouble y);	//in version 2.31,parameter (UGdouble *y) was changed to (UGdouble y).
	static void  build_sbt(UGint *entries, UGdouble *sbt, sb_tree *sbtree);
	static void  free_sbtree(sb_tree **sbtree);
	static UGint   count_optimal_vertices(gpc_list c);
	static edge_node  *build_lmt(lmt_node **lmt, sb_tree **sbtree,
                            UGint *sbt_entries, gpc_polygon *p, UGint type,
                            UGint op);
	//{{ by guohui 2007.09.30 ���½ӿ�����ʹ�ã��ڲ���ʱ�ȷ�ա�������Ҫ�������д�
	//static edge_node* build_lmt2(lmt_node **lmt, double *sbtree,   // sbtree ��Ҫ�����湹����������εĵ������ܺ͸�doubleֵ
	//						 UGint *sbt_entries, gpc_polygon *p, UGint type,
	//						 UGint op);
	//}} by guohui 2007.09.30 ���½ӿ�����ʹ�ã��ڲ���ʱ�ȷ�ա�������Ҫ�������д�

/*
===========================================================================
                       Public Function Prototypes
===========================================================================
*/
protected:
#ifdef GPC_VERSION_231
	static void gpc_add_contour (gpc_polygon *polygon,gpc_list *contour,UGint hole);					//GPC version add a parameter: UGint hole
#else
	static void gpc_add_contour(gpc_polygon *p, gpc_list *new_contour);
#endif

//{{ by guohui 2007.09.30 ���½ӿ�����ʹ�ã��ڲ���ʱ�ȷ�ա�������Ҫ�������д�	
//	static void gpc_tristrip_clip (UGint set_operation,gpc_polygon *subject_polygon,
//                              gpc_polygon *clip_polygon,gpc_tristrip *result_tristrip);
//	static void gpc_polygon_to_tristrip (gpc_polygon     *polygon,
//                              gpc_tristrip    *tristrip);
//}} by guohui 2007.09.30 ���½ӿ�����ʹ�ã��ڲ���ʱ�ȷ�ա�������Ҫ�������д�

	static void gpc_free_tristrip (gpc_tristrip *tristrip);
public:
	static void gpc_free_polygon (gpc_polygon *polygon);

protected:
	static void  add_intersection(it_node **it, edge_node *edge0,
									edge_node *edge1, UGdouble x, UGdouble y);
	static void   add_st_edge(st_node **st, it_node **it, edge_node *edge,UGdouble xtop);
	static void   build_intersection_table(it_node **it, edge_node *aet, UGdouble yt);
	static UGint  count_vertices(vertex_node *vertex);
	static UGint  count_contours(polygon_node *polygon);
	static void   add_left(polygon_node *P, UGdouble x, UGdouble y);
	static void   merge_left(polygon_node *P,polygon_node *Q, polygon_node *list);
	static void   add_right(polygon_node *P, UGdouble x, UGdouble y);
	static void   merge_right(polygon_node *P, polygon_node *Q, polygon_node *list);
	static void   add_local_min(polygon_node **P, edge_node *edge,UGdouble x, UGdouble y);
	static UGint  count_tristrips(polygon_node *tn);
	static void   add_vertex(vertex_node **t, UGdouble x, UGdouble y);
	static void   new_tristrip(polygon_node **tn, edge_node *edge,UGdouble x, UGdouble y);
	static void   add_edge_to_aet(edge_node **aet, edge_node *edge, edge_node *prev);

	static void	  add_to_sbtree(UGint *entries, sb_tree **sbtree, UGdouble* y);

public:

	//! \brief 		SuperMap��������ݽṹת�� GPC �ṹ
	//! \return 	void
	//! \param 		pPoints			SuperMap����νṹ�еĵ㴮
	//! \param 		lPolyCount		SuperMap����νṹ��ÿ���Ӷ���ε���
	//! \param 		lCount			SuperMap����νṹ�е��Ӷ���θ���
	//! \param 		polygon			���� GPC �Ķ���Ρ�
	//! \remarks 	û�а�pPoints���ݸ��Ƶ�gpc�ṹ�У����� gpc_polygon ��Ҫ�ͷ�ָ�롣	
	//				Supermap��������ݽṹת��gpc_polygon�ṹ,Supermap����νṹ�ο�CSmGeoRegion.
	//				gpc_polygon* polygon:  gpc��������ݽṹ,�ο�gpc_polygon struct.
	static void   Sm_To_Gpc(UGPoint2D *pPoints,UGint* lPolyCount,UGint lCount,gpc_polygon* polygon);	
	
	//
	//! \brief 		SuperMap��������ݽṹת�� GPC �ṹ(���ӿ��ѷ�����������ʹ��)
	//! \return 	void
	//! \param 		pPoints			SuperMap����νṹ�еĵ㴮
	//! \param 		lPolyCount		SuperMap����νṹ��ÿ���Ӷ���ε���
	//! \param 		lCount			SuperMap����νṹ�е��Ӷ���θ���
	//! \param 		polygon			���� GPC �Ķ���Ρ�
	//! \remarks 	�ѷ����ĺ������൱��gpc_to_SM
	static void   gpc_read_polygon(const UGPoint2D *pPoints,const UGint* lPolyCount,UGint lCount ,gpc_polygon *polygon);

	//! \brief 		gpc_polygon�ṹת��Supermap��������ݽṹ.
	//! \return 	void
	//! \param 		pPoints			SuperMap����νṹ�еĵ㴮
	//! \param 		lPolyCount		SuperMap����νṹ��ÿ���Ӷ���ε���
	//! \param 		lCount			SuperMap����νṹ�е��Ӷ���θ���
	//! \param 		polygon			GPC �Ķ���Ρ�
	//! \remarks 	gpc�ṹ�е������Ƶ�*pPoints�У��ڲ��ͷ���gpc�����ݡ�
	//! \remarks 	��ˣ���ȷ�� polygon �����ݵ�ָ����� delete��
	static void   Gpc_to_Sm(UGPoint2D **pPoints,UGint **lPolyCount,UGint& lCount,gpc_polygon *polygon);

	//����β������� 
	//UGint set_operation: �������ͣ��ο�ö�����Ͷ���.
	//������������Σ���������result_polygon��
	

	//! \brief 		����β�������
	//! \return 	void
	//! \param 		set_operation	��������(Difference,Intersect,Union,Xor)
	//! \param 		subject_polygon	���������(GPC����νṹ)
	//! \param 		clip_polygon	�������(GPC����νṹ)
	//! \param 		result_polygon	������(GPC����νṹ)
	//! \remarks 	
	static void gpc_polygon_clip (UGint set_operation, gpc_polygon *subject_polygon,
		gpc_polygon *clip_polygon,gpc_polygon* result_polygon);
	
//new functions in version 2.31
protected:
	static bbox * create_contour_bboxes(gpc_polygon *p);
	static void  minimax_test(gpc_polygon *subj, gpc_polygon *clip, UGint op);
	static inline UGbool EQ(UGdouble &a, UGdouble &b)
	{
		if (a > 1 || a < -1){return (fabs((a) - (b)) <= GPC_EPSILON);}
		UGdouble dMaxValue = UGMAX(fabs(a),fabs(b));UGdouble dAbsolute = a - b;
		return ((dAbsolute>=(dMaxValue*(-1.0e-9))) && (dAbsolute<=(dMaxValue*(1.0e-9))));
	}
	static inline UGbool NE(UGdouble &a, UGdouble &b){return !EQ(a,b);}
	static inline UGbool GT(UGdouble &a, UGdouble &b){return ((!EQ(a,b)) && (a>b));}
	static inline UGbool LT(UGdouble &a, UGdouble &b){return ((!EQ(a,b)) && (b>a));}
};

}


#endif // !defined(AFX_SMGENERALPOLYGONCLIPEX_H__E26C084A_320F_44A0_BB96_1A094672DD17__INCLUDED_)
