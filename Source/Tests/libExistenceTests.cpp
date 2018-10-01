
 # i n c l u d e   < l i b C o r e / l i b C o r e . h >  
 # i n c l u d e   < l i b C o r e / R e f P t r . h >  
 # i n c l u d e   < l i b C o r e / W e a k P t r . h >  
 # i n c l u d e   < l i b H a r n e s s e d / l i b H a r n e s s e d . h >  
  
 # i n c l u d e   < l i b E x i s t e n c e / l i b E x i s t e n c e . h >  
 # i n c l u d e   < l i b E x i s t e n c e / E n g i n e . h >  
 # i n c l u d e   < l i b E x i s t e n c e / S y s t e m . h >  
 # i n c l u d e   < l i b E x i s t e n c e / C o m p o n e n t . h >  
 # i n c l u d e   < l i b E x i s t e n c e / E n t i t y . h >  
  
 # i n c l u d e   < l i b M i r r o r / l i b M i r r o r . h >  
 # i n c l u d e   < l i b M i r r o r / O b j e c t . h >  
  
 u s i n g   n a m e s p a c e   F i r e s t o r m ;  
  
 u s i n g   s t d : : c o u t ;  
 u s i n g   s t d : : c i n ;  
 u s i n g   s t d : : e n d l ;  
  
 # d e f i n e   H A N D L E _ E R R O R (   R E S ,   T A G   )   \  
 	 i f ( ! R E S . h a s _ v a l u e ( ) )   \  
 	 	 t . A s s e r t ( R E S . h a s _ v a l u e ( ) ,   " o p e r a t i o n   t a g g e d   ' "   T A G   " ' r e t u r n e d   a n   u n e x p e c t e d   e r r o r   :   " + R E S . e r r o r ( ) . M e s s a g e )  
  
  
  
  
  
/* c l a s s   T e s t C o m p o n e n t _ P l u r a l   :   p u b l i c   C o m p o n e n t  
 {  
 	 F I R E _ M I R R O R _ D E C L A R E ( T e s t C o m p o n e n t _ P l u r a l ,   C o m p o n e n t ) ;  
 p u b l i c :  
 	 T e s t C o m p o n e n t _ P l u r a l ( )   { }  
 	 v i r t u a l   ~ T e s t C o m p o n e n t _ P l u r a l ( )   { }  
 p r i v a t e :  
 	 v i r t u a l   v o i d *   D o I n s p e c t ( M i r r o r : : T y p e   t y p e )   o v e r r i d e  
 	 {  
 	 	 i f   ( t y p e   = =   T e s t C o m p o n e n t _ P l u r a l : : M y T y p e ( ) )  
 	 	 {  
 	 	 	 r e t u r n   t h i s ;  
 	 	 }  
 	 	 r e t u r n   C o m p o n e n t : : D o I n s p e c t ( t y p e ) ;  
 	 }  
 } ;  
  
 c l a s s   T e s t C o m p o n e n t _ S i n g l e t o n   :   p u b l i c   C o m p o n e n t  
 {  
 	 F I R E _ M I R R O R _ D E C L A R E ( T e s t C o m p o n e n t _ S i n g l e t o n ,   C o m p o n e n t ) ;  
 p u b l i c :  
 	 T e s t C o m p o n e n t _ S i n g l e t o n ( )   { }  
 	 v i r t u a l   ~ T e s t C o m p o n e n t _ S i n g l e t o n ( )   { }  
 p r i v a t e :  
 	 v i r t u a l   v o i d *   D o I n s p e c t ( M i r r o r : : T y p e   t y p e )   o v e r r i d e  
 	 {  
 	 	 i f ( t y p e   = =   T e s t C o m p o n e n t _ S i n g l e t o n : : M y T y p e ( ) )  
 	 	 {  
 	 	 	 r e t u r n   t h i s ;  
 	 	 }  
 	 	 r e t u r n   C o m p o n e n t : : D o I n s p e c t ( t y p e ) ;  
 	 }  
 } ;  
  
  
 c l a s s   T e s t S y s t e m _ 1   :   p u b l i c   S y s t e m  
 {  
 	 F I R E _ M I R R O R _ D E C L A R E ( T e s t S y s t e m _ 1 ,   S y s t e m ) ;  
 p r i v a t e :  
 	 v i r t u a l   v o i d   O n M o d i f i e d ( d o u b l e   d e l t a T )   o v e r r i d e ;  
 	 v i r t u a l   v o i d   O n E n t i t y A d d e d ( c o n s t   W e a k P t r < E n t i t y > &   e n t i t y )   o v e r r i d e ;  
 	 v i r t u a l   v o i d   O n E n t i t y R e m o v e d ( c o n s t   W e a k P t r < E n t i t y > &   e n t i t y )   o v e r r i d e ;  
 	 v i r t u a l   v o i d   O n B e f o r e A d d T o E n g i n e ( )   o v e r r i d e ;  
 	 v i r t u a l   v o i d   O n A d d T o E n g i n e ( )   o v e r r i d e ;  
 	 v i r t u a l   v o i d   O n R e m o v e F r o m E n g i n e ( )   o v e r r i d e ;  
 	 v i r t u a l   v o i d   O n T i c k ( d o u b l e   d e l t a T ,   c o n s t   V e c t o r < W e a k P t r < E n t i t y > > &   e n t i t i e s )   o v e r r i d e ;  
 	 v i r t u a l   b o o l   O n E n t i t y F i l t e r ( c o n s t   W e a k P t r < E n t i t y > &   e n t i t y )   c o n s t   o v e r r i d e ;  
  
 	 v i r t u a l   v o i d *   D o I n s p e c t ( M i r r o r : : T y p e   t y p e )   o v e r r i d e  
 	 {  
 	 	 i f ( t y p e   = =   T e s t S y s t e m _ 1 : : M y T y p e ( ) )  
 	 	 {  
 	 	 	 r e t u r n   t h i s ;  
 	 	 }  
 	 	 r e t u r n   S y s t e m : : D o I n s p e c t ( t y p e ) ;  
 	 }  
 } ;  
  
 v o i d   T e s t S y s t e m _ 1 : : O n M o d i f i e d ( d o u b l e   d e l t a T )  
 {  
 }  
  
 v o i d   T e s t S y s t e m _ 1 : : O n E n t i t y A d d e d ( c o n s t   W e a k P t r < E n t i t y > &   e n t i t y )  
 {  
 }  
  
 v o i d   T e s t S y s t e m _ 1 : : O n E n t i t y R e m o v e d ( c o n s t   W e a k P t r < E n t i t y > &   e n t i t y )  
 {  
 }  
  
 v o i d   T e s t S y s t e m _ 1 : : O n B e f o r e A d d T o E n g i n e ( )  
 {  
 }  
  
 v o i d   T e s t S y s t e m _ 1 : : O n A d d T o E n g i n e ( )  
 {  
 }  
  
 v o i d   T e s t S y s t e m _ 1 : : O n R e m o v e F r o m E n g i n e ( )  
 {  
 }  
  
 v o i d   T e s t S y s t e m _ 1 : : O n T i c k ( d o u b l e   d e l t a T ,   c o n s t   V e c t o r < W e a k P t r < E n t i t y > > &   e n t i t i e s )  
 {  
 }  
  
 b o o l   T e s t S y s t e m _ 1 : : O n E n t i t y F i l t e r ( c o n s t   W e a k P t r < E n t i t y > &   e n t i t y )   c o n s t  
 {  
 	 r e t u r n   e n t i t y . l o c k ( ) - > I n s p e c t < T e s t C o m p o n e n t _ P l u r a l > ( )   ! =   n u l l p t r ;  
 }  
  
 F I R E _ M I R R O R _ D E F I N E ( T e s t S y s t e m _ 1 )  
 {  
 	 C l a s s . c o n s t r u c t o r < > ( )  
 	 (  
 	 	 r t t r : : p o l i c y : : c t o r : : a s _ r a w _ p t r  
 	 ) ;  
 }  
  
 F I R E _ M I R R O R _ D E F I N E ( T e s t C o m p o n e n t _ P l u r a l )  
 {  
 	 C l a s s  
 	 (  
 	 	 M i r r o r : : M e t a ( C o m p o n e n t M e t a d a t a : : k P l u r a l ,   t r u e )  
 	 )  
 	 . c o n s t r u c t o r < > ( )  
 	 (  
 	 	 r t t r : : p o l i c y : : c t o r : : a s _ r a w _ p t r  
 	 ) ;  
 }  
  
 F I R E _ M I R R O R _ D E F I N E ( T e s t C o m p o n e n t _ S i n g l e t o n )  
 {  
 	 C l a s s . c o n s t r u c t o r < > ( )  
 	 (  
 	 	 r t t r : : p o l i c y : : c t o r : : a s _ r a w _ p t r  
 	 ) ;  
 }  */
  
  
  
 R e f P t r < T e s t H a r n e s s >   l i b E x i s t e n c e P r e p a r e H a r n e s s ( i n t   a r g c ,   c h a r * *   a r g v )  
 {  
 	/* T e s t S y s t e m _ 1 : : R e g i s t e r R e f l e c t i o n ( ) ;  
 	 T e s t C o m p o n e n t _ P l u r a l : : R e g i s t e r R e f l e c t i o n ( ) ;  
 	 T e s t C o m p o n e n t _ S i n g l e t o n : : R e g i s t e r R e f l e c t i o n ( ) ;  */
  
 	 R e f P t r < T e s t H a r n e s s >   h ( n e w   T e s t H a r n e s s ( " l i b E x i s t e n c e   T e s t s " ) ) ;  
  
 	 / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /  
 	 / /   B e g i n   O b j e c t P o o l   T e s t i n g  
 	 / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /  
 	 / * h . I t ( " o b j e c t   p o o l s   s h o u l d   i n s t a n t i a t e   w i t h   t h e   c o r r e c t   n u m b e r   o f   o b j e c t s " ,   [ ] ( F i r e s t o r m : : T e s t C a s e &   t )   {  
 	 	 F i r e s t o r m : : O b j e c t P o o l < P o o l e d O b j >   o b j P o o l ( 5 0 0 ) ;  
 	 	 t . A s s e r t ( o b j P o o l . G e t O b j e c t B l o c k S i z e ( )   = =   1 5 0 0 ,   " o b j e c t   b l o c k   s i z e   w a s   i n c o r r e c t " ) ;  
 	 	 t . A s s e r t ( o b j P o o l . G e t F l a g B l o c k S i z e ( )   = =   5 0 0 ,   " f l a g   b l o c k   s i z e   w a s   i n c o r r e c t " ) ;  
 	 } ) ;  
  
 	 h . I t ( " o b j e c t   p o o l s   s h o u l d   r e t u r n   v a l i d   p o i n t e r s   w h e n   A c q u i r e   i s   c a l l e d " ,   [ ] ( F i r e s t o r m : : T e s t C a s e &   t )   {  
 	 	 F i r e s t o r m : : O b j e c t P o o l < P o o l e d O b j >   o b j P o o l ( 5 0 0 ) ;  
 	 	 F i r e s t o r m : : R e s u l t < F i r e s t o r m : : R e f P t r < P o o l e d O b j > , F i r e s t o r m : : E r r o r >   o b j   =   o b j P o o l . A c q u i r e ( ) ;  
 	 	 H A N D L E _ E R R O R ( o b j ,   " o b j P o o l . A c q u i r e " ) ;  
 	 	 t . A s s e r t ( o b j . v a l u e ( ) . G e t ( )   ! =   n u l l p t r ,   " c o u l d   n o t   a c q u i r e   o b j e c t   f r o m   p o o l " ) ;  
 	 } ) ;  
  
 	 h . I t ( " o b j e c t s   a c q u i r e d   f r o m   t h e   p o o l   s h o u l d   b e   m a r k e d   a s   ' i n   u s e '   w h e n   t h e y ' r e   a c t i v e " ,   [ ] ( F i r e s t o r m : : T e s t C a s e &   t )   {  
 	 	 F i r e s t o r m : : O b j e c t P o o l < P o o l e d O b j >   o b j P o o l ( 1 0 ) ;  
 	 	 {  
 	 	 	 F i r e s t o r m : : R e s u l t < F i r e s t o r m : : R e f P t r < P o o l e d O b j > , F i r e s t o r m : : E r r o r >   o b j   =   o b j P o o l . A c q u i r e ( ) ;  
 	 	 	 H A N D L E _ E R R O R ( o b j ,   " o b j P o o l . A c q u i r e " ) ;  
  
 	 	 	 F i r e s t o r m : : R e s u l t < b o o l ,   F i r e s t o r m : : E r r o r >   r e s u l t   =   o b j P o o l . I s I n U s e ( o b j . v a l u e ( ) . G e t ( ) ) ;  
 	 	 	 H A N D L E _ E R R O R ( r e s u l t ,   " o b j P o o l . I s I n U s e " ) ;  
  
 	 	 	 i f ( r e s u l t . h a s _ v a l u e ( ) )  
 	 	 	 {  
 	 	 	 	 t . A s s e r t ( r e s u l t . v a l u e ( ) ,   " o b j e c t   i s   n o t   m a r k e d   a s   b e i n g   i n   u s e   w h e n   i t   s h o u l d   b e " ) ;  
 	 	 	 }  
 	 	 }  
 	 } ) ;  
  
 	 h . I t ( " o b j e c t   p o o l s   s h o u l d   r e t u r n   i n v a l i d   p o i n t e r s   w h e n   A c q u i r e   i s   c a l l e d   a n d   t h e r e   a r e   n o   m o r e   o b j e c t s " ,    
 	 	 [ ] ( F i r e s t o r m : : T e s t C a s e &   t )   {  
 	 	 F i r e s t o r m : : O b j e c t P o o l < P o o l e d O b j >   o b j P o o l ( 5 0 0 ) ;  
 	 	 F i r e s t o r m : : R e f P t r < P o o l e d O b j >   o b j s [ 5 0 0 ] ;  
 	 	 f o r ( i n t   i   =   0 ;   i   <   5 0 0 ;   i + + )  
 	 	 {  
 	 	 	 F i r e s t o r m : : R e s u l t < F i r e s t o r m : : R e f P t r < P o o l e d O b j > ,   F i r e s t o r m : : E r r o r >   o b j   =   o b j P o o l . A c q u i r e ( ) ;  
 	 	 	 t . A s s e r t ( o b j . h a s _ v a l u e ( ) ,   " o b j P o o l   r e t u r n e d   a n   e r r o r   w h e n   i t   s h o u l d n ' t   h a v e " ) ;  
 	 	 	 o b j s [ i ]   =   o b j . v a l u e ( ) ;  
 	 	 }  
 	 	 F i r e s t o r m : : R e s u l t < F i r e s t o r m : : R e f P t r < P o o l e d O b j > ,   F i r e s t o r m : : E r r o r >   o b j   =   o b j P o o l . A c q u i r e ( ) ;  
 	 	 t . A s s e r t ( ! o b j . h a s _ v a l u e ( ) ,   " o b j e c t   p o o l   s h o u l d   h a v e   r e t u r n e d   a n   e r r o r .   i t   d i d n ' t . " ) ;  
 	 } ) ; * /  
 	 / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /  
 	 / /   E n d   O b j e c t P o o l   T e s t i n g  
 	 / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /  
  
  
 	 / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /  
 	 / /   B e g i n   E C S   T e s t i n g  
 	 / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /  
/* 	 h - > I t ( " [ E C S ]   E n t i t i e s   s h o u l d   b e   i n s t a n t i a b l e   a n d   s h o u l d   b e   a b l e   t o   h a v e   c o m p o n e n t s   a d d e d   t o   t h e m " ,   [ ] ( T e s t C a s e &   t )   {  
 	 	 E n t i t y   e n t i t y ;  
 	 	 M i r r o r : : T y p e   t y p e   =   M i r r o r : : T y p e : : g e t < T e s t C o m p o n e n t _ S i n g l e t o n > ( ) ;  
 	 	 e n t i t y . A d d C o m p o n e n t < T e s t C o m p o n e n t _ S i n g l e t o n > ( ) ;  
 	 	 t . A s s e r t ( e n t i t y . G e t N u m C o m p o n e n t s ( )   = =   1 ,   " t h e   t e s t   e n t i t y   h a d   t h e   w r o n g   n u m b e r   o f   c o m p o n e n t s   i n s i d e   o f   i t " ) ;  
  
 	 	 T e s t C o m p o n e n t _ S i n g l e t o n *   t e s t C o m p o n e n t   =   e n t i t y . I n s p e c t < T e s t C o m p o n e n t _ S i n g l e t o n > ( ) ;  
 	 	 t . A s s e r t ( t e s t C o m p o n e n t   ! =   n u l l p t r ,   " t h e   t e s t   c o m p o n e n t   c o u l d   n o t   b e   r e t r i e v e d   f r o m   t h e   e n t i t y   v i a   i n s p e c t i o n " ) ;  
 	 } ) ;  
  
 	 h - > I t ( " [ E C S ]   E n t i t i e s   s h o u l d   n o t   r e t u r n   p o i n t e r s   t o   c o m p o n e n t s   t h e y   d o   n o t   h a v e   [ n o t h r o w ] " ,   [ ] ( T e s t C a s e &   t )   {  
 	 	 E n t i t y   e n t i t y ;  
 	 	 e n t i t y . A d d C o m p o n e n t < T e s t C o m p o n e n t _ P l u r a l > ( ) ;  
 	 	 t . A s s e r t ( e n t i t y . G e t N u m C o m p o n e n t s ( )   = =   1 ,   " t h e   t e s t   e n t i t y   h a d   t h e   w r o n g   n u m b e r   o f   c o m p o n e n t s   i n s i d e   o f   i t " ) ;  
  
 	 	 T e s t C o m p o n e n t _ S i n g l e t o n *   t e s t C o m p o n e n t   =   e n t i t y . I n s p e c t < T e s t C o m p o n e n t _ S i n g l e t o n > ( ) ;  
 	 	 t . A s s e r t ( t e s t C o m p o n e n t   = =   n u l l p t r ,   " t h e   t e s t   e n t i t y   r e t u r n e d   a   p o i n t e r   t o   a   c o m p o n e n t   i t   s h o u l d n ' t   h a v e " ) ;  
 	 } ) ;  
  
 	 h - > I t ( " [ E C S ]   E n t i t i e s   s h o u l d   o n l y   b e   a l l o w e d   a   s i n g l e   i n s t a n c e   o f   a   s i n g l e t o n   c o m p o n e n t " ,   [ ] ( T e s t C a s e &   t )   {  
 	 	 E n t i t y   e n t i t y ;  
 	 	 b o o l   r e s u l t   =   e n t i t y . A d d C o m p o n e n t < T e s t C o m p o n e n t _ S i n g l e t o n > ( ) ;  
 	 	 t . A s s e r t I s T r u e ( r e s u l t ,   " t h e   o p e r a t i o n   t o   a d d   a   s i n g l e t o n   c o m p o n e n t   t o   t h e   e n t i t y   f a i l e d   [ t e m p l a t e ] " ) ;  
  
 	 	 s i z e _ t   n u m C o m p o n e n t s   =   e n t i t y . G e t N u m C o m p o n e n t s ( ) ;  
 	 	 t . A s s e r t ( n u m C o m p o n e n t s   = =   1 ,   " t h e   t e s t   e n t i t y   h a d   t h e   w r o n g   n u m b e r   o f   c o m p o n e n t s   i n s i d e   o f   i t " ) ;  
  
 	 	 T e s t C o m p o n e n t _ S i n g l e t o n *   t e s t C o m p o n e n t   =   e n t i t y . I n s p e c t < T e s t C o m p o n e n t _ S i n g l e t o n > ( ) ;  
 	 	 t . A s s e r t N o t N u l l ( t e s t C o m p o n e n t ,   " t h e   t e s t   e n t i t y   r e t u r n e d   a   p o i n t e r   t o   a   c o m p o n e n t   i t   s h o u l d n ' t   h a v e " ) ;  
  
 	 	 r e s u l t   =   e n t i t y . A d d C o m p o n e n t < T e s t C o m p o n e n t _ S i n g l e t o n > ( ) ;  
 	 	 t . A s s e r t I s F a l s e ( r e s u l t ,   " a d d i n g   t h e   s e c o n d   s i n g l e t o n   s h o u l d   h a v e   r e t u r n e d   f a l s e   [ t e m p l a t e ] " ) ;  
  
 	 	 r e s u l t   =   e n t i t y . A d d C o m p o n e n t ( T e s t C o m p o n e n t _ S i n g l e t o n : : M y T y p e ( ) ) ;  
 	 	 t . A s s e r t I s F a l s e ( r e s u l t ,   " a d d i n g   t h e   s e c o n d   s i n g l e t o n   s h o u l d   h a v e   r e t u r n e d   f a l s e   [ M i r r o r : : T y p e ] " ) ;  
  
 	 	 n u m C o m p o n e n t s   =   e n t i t y . G e t N u m C o m p o n e n t s ( ) ;  
 	 	 t . A s s e r t ( n u m C o m p o n e n t s   = =   1 ,   " t h e   e n t i t y   r e p o r t e d   > 1   s i n g l e t o n   c o m p o n e n t   w h e n   i t   s h o u l d   o n l y   h a v e   o n e " ) ;  
 	 } ) ;  
  
 	 h - > I t ( " [ E C S ]   E n t i t i e s   s h o u l d   b e   a l l o w e d   t o   h a v e   m o r e   t h a n   o n e   o f   a   p l u r a l   c o m p o n e n t " ,   [ ] ( T e s t C a s e &   t )   {  
 	 	 E n t i t y   e n t i t y ;  
 	 	 b o o l   r e s u l t   =   e n t i t y . A d d C o m p o n e n t < T e s t C o m p o n e n t _ P l u r a l > ( ) ;  
 	 	 t . A s s e r t I s T r u e ( r e s u l t ,   " t h e   o p e r a t i o n   t o   a d d   a   s i n g l e t o n   c o m p o n e n t   t o   t h e   e n t i t y   f a i l e d " ) ;  
  
 	 	 s i z e _ t   n u m C o m p o n e n t s   =   e n t i t y . G e t N u m C o m p o n e n t s ( ) ;  
 	 	 t . A s s e r t ( n u m C o m p o n e n t s   = =   1 ,   " t h e   t e s t   e n t i t y   h a d   t h e   w r o n g   n u m b e r   o f   c o m p o n e n t s   i n s i d e   o f   i t " ) ;  
  
 	 	 r e s u l t   =   e n t i t y . A d d C o m p o n e n t < T e s t C o m p o n e n t _ P l u r a l > ( ) ;  
 	 	 t . A s s e r t I s T r u e ( r e s u l t ,   " a d d i n g   t h e   s e c o n d   p l u r a l   s h o u l d   h a v e   r e t u r n e d   t r u e   [ t e m p l a t e ] " ) ;  
 	 	 n u m C o m p o n e n t s   =   e n t i t y . G e t N u m C o m p o n e n t s ( ) ;  
 	 	 t . A s s e r t ( n u m C o m p o n e n t s   = =   2 ,   " t h e   t e s t   e n t i t y   h a d   t h e   w r o n g   n u m b e r   o f   c o m p o n e n t s   i n s i d e   o f   i t " ) ;  
  
 	 	 r e s u l t   =   e n t i t y . A d d C o m p o n e n t ( T e s t C o m p o n e n t _ P l u r a l : : M y T y p e ( ) ) ;  
 	 	 t . A s s e r t I s T r u e ( r e s u l t ,   " a d d i n g   t h e   t h i r d   p l u r a l   s h o u l d   h a v e   r e t u r n e d   t r u e   [ M i r r o r : : T y p e ] " ) ;  
 	 	 n u m C o m p o n e n t s   =   e n t i t y . G e t N u m C o m p o n e n t s ( ) ;  
 	 	 t . A s s e r t ( n u m C o m p o n e n t s   = =   3 ,   " t h e   t e s t   e n t i t y   h a d   t h e   w r o n g   n u m b e r   o f   c o m p o n e n t s   i n s i d e   o f   i t " ) ;  
 	 } ) ;  
  
 	 h - > I t ( " [ E C S ]   E n g i n e s   s h o u l d   b e   a b l e   t o   h a v e   s y s t e m s   a d d e d   t o   i t " ,   [ ] ( F i r e s t o r m : : T e s t C a s e &   t )   {  
 	 	 E n g i n e   e n g i n e ;  
 	 	 e n g i n e . A d d S y s t e m < T e s t S y s t e m _ 1 > ( ) ;  
 	 	 e n g i n e . U p d a t e ( 0 . 0 ) ;  
  
 	 	 t . A s s e r t ( e n g i n e . G e t N u m S y s t e m s ( )   = =   1 ,   " t h e   t e s t   e n g i n e   h a d   t h e   w r o n g   n u m b e r   o f   s y s t e m s   i n s i d e   o f   i t " ) ;  
 	 } ) ;  
  
 	 h - > I t ( " [ E C S ]   E n g i n e s   s h o u l d   h a v e   t h e   c o r r e c t   n u m b e r   o f   S y s t e m s   w i t h i n   t h e m   a f t e r   o n e   i s   r e m o v e d " ,   [ ] ( F i r e s t o r m : : T e s t C a s e &   t )   {  
 	 	 E n g i n e   e n g i n e ;  
 	 	 e n g i n e . A d d S y s t e m < T e s t S y s t e m _ 1 > ( ) ;  
 	 	 e n g i n e . U p d a t e ( 0 . 0 ) ;  
  
 	 	 t . A s s e r t ( e n g i n e . G e t N u m S y s t e m s ( )   = =   1 ,   " t h e   t e s t   e n g i n e   h a d   t h e   w r o n g   n u m b e r   o f   s y s t e m s   i n s i d e   o f   i t   b e f o r e   r e m o v i n g   i t " ) ;  
  
 	 	 e n g i n e . R e m o v e S y s t e m < T e s t S y s t e m _ 1 > ( ) ;  
 	 	 e n g i n e . U p d a t e ( 0 . 0 ) ;  
  
 	 	 t . A s s e r t ( e n g i n e . G e t N u m S y s t e m s ( )   = =   0 ,   " t h e   t e s t   e n g i n e   h a d   t h e   w r o n g   n u m b e r   o f   s y s t e m s   i n s i d e   o f   i t   a f t e r   r e m o v i n g   i t " ) ;  
 	 } ) ;  
  
 	 h - > I t ( " [ E C S ]   S y s t e m s   s h o u l d   h a v e   E n t i t i e s   t h a t   a r e   a d d a b l e   t o   t h e m " ,   [ ] ( F i r e s t o r m : : T e s t C a s e &   t )   {  
 	 	 E n g i n e   e n g i n e ;  
 	 	 e n g i n e . A d d S y s t e m < T e s t S y s t e m _ 1 > ( ) ;  
 	 	 e n g i n e . U p d a t e ( 0 . 0 ) ;  
  
 	 	 t . A s s e r t ( e n g i n e . G e t N u m S y s t e m s ( )   = =   1 ,   " t h e   t e s t   e n g i n e   h a d   t h e   w r o n g   n u m b e r   o f   s y s t e m s   i n s i d e   o f   i t " ) ;  
  
 	 	 R e f P t r < E n t i t y >   e ( n e w   E n t i t y ) ;  
 	 	 b o o l   r e s u l t   =   e - > A d d C o m p o n e n t < T e s t C o m p o n e n t _ P l u r a l > ( ) ;  
 	 	 t . A s s e r t I s T r u e ( r e s u l t ,   " a d d i n g   a   p l u r a l   c o m p o n e n t   t o   t h e   e n t i t y   f a i l e d " ) ;  
 	 	 t . A s s e r t ( e - > G e t N u m C o m p o n e n t s ( )   = =   1 ,   " t h e   t e s t   e n t i t y   d i d   n o t   h a v e   t h e   c o r r e c t   n u m b e r   o f   c o m p o n e n t s " ) ;  
  
 	 	 e n g i n e . A d d E n t i t y ( e ) ;  
 	 	 e n g i n e . U p d a t e ( 0 . 0 ) ;  
 	 } ) ;  
  
 	 h - > I t ( " [ E C S ]   E n g i n e s   s h o u l d   o n l y   e v e r   h a v e   o n e   s y s t e m   o f   a   g i v e n   t y p e   r e g i s t e r e d   a t   a   t i m e " ,   [ ] ( F i r e s t o r m : : T e s t C a s e &   t )   {  
 	 	 E n g i n e   e n g i n e ;  
 	 	 e n g i n e . A d d S y s t e m < T e s t S y s t e m _ 1 > ( ) ;  
 	 	 e n g i n e . U p d a t e ( 0 . 0 ) ;  
  
 	 	 t . A s s e r t ( e n g i n e . G e t N u m S y s t e m s ( )   = =   1 ,   " t h e   t e s t   e n g i n e   h a d   t h e   w r o n g   n u m b e r   o f   s y s t e m s   i n s i d e   o f   i t " ) ;  
  
 	 	 e n g i n e . A d d S y s t e m < T e s t S y s t e m _ 1 > ( ) ;  
 	 	 e n g i n e . U p d a t e ( 0 . 0 ) ;  
  
 	 	 t . A s s e r t ( e n g i n e . G e t N u m S y s t e m s ( )   = =   1 ,   " t h e   t e s t   e n g i n e   h a d   a   d u p l i c a t e   s y s t e m   o f   a   t y p e   i n s i d e   o f   i t " ) ;  
 	 } ) ;  */
 	 / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /  
 	 / /   E n d   E C S   T e s t i n g  
 	 / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /  
  
 	 r e t u r n   h ;  
 } 
