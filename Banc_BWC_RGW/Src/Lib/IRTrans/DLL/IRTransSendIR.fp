s��         I     �  �   �   I����                                                               IRTrans.SendIR                              CVIFUNC                                                      0  System_Windows_Forms_Form *[]     /  System_Windows_Forms_Form []     . ��System_Windows_Forms_Form **     - ��System_Windows_Forms_Form *     , ��System_Windows_Forms_Form     +  IRTrans_NET_IRTransServer *[]     *  IRTrans_NET_IRTransServer []     ) ��IRTrans_NET_IRTransServer **     ( ��IRTrans_NET_IRTransServer *     ' ��IRTrans_NET_IRTransServer     &  IRTrans_SendIR_SendIR *[]     %  IRTrans_SendIR_SendIR []     $ ��IRTrans_SendIR_SendIR **     # ��IRTrans_SendIR_SendIR *     " ��IRTrans_SendIR_SendIR     ! 	 
ssize_t *[]     
   	ssize_t []     
 
��ssize_t **     	 	��ssize_t *      ��ssize_t     
  	size_t *[]     	  size_t []     	 	��size_t **      ��size_t *      ��size_t       CDotNetAssemblyHandle *[]       CDotNetAssemblyHandle []      ��CDotNetAssemblyHandle **      ��CDotNetAssemblyHandle *      ��CDotNetAssemblyHandle       CDotNetHandle *[]       CDotNetHandle []      ��CDotNetHandle **      ��CDotNetHandle *      ��CDotNetHandle     	  void **[]       void *[]      ��void ***     
 ��void **     		  char **[]      ��char ***     
  	double *[]     	 	��double **      ��double *     	  float *[]      ��float **      ��float *       unsigned __int64 *[]        unsigned __int64 []     � ��unsigned __int64 **     � ��unsigned __int64 *     � ��unsigned __int64     � 	 
__int64 *[]     
�  	__int64 []     
� 
��__int64 **     	� 	��__int64 *     � ��__int64     �  unsigned char *[]     � ��unsigned char **     � ��unsigned char *     � ��char **     �  unsigned short *[]     � ��unsigned short **     � ��unsigned short *     	�  short *[]     � ��short **     � ��short *     �  unsigned int *[]     � ��unsigned int **     � ��unsigned int *     �  int *[]     � ��int **     � ��int *  �    LabWindows/CVI .NET controller instrument wrapper for IRTrans.SendIR, Version=1.0.7.29762, Culture=neutral, PublicKeyToken=null.

The target assembly name is specified by the '__assemblyName' constant in the generated source file. If there are multiple versions of this assembly, and you want .NET to determine and load the appropriate one, then you can remove the version, culture, and public key information from the constant and just specify the name of the assembly.     t    Initializes this CVI .NET controller.

Call this function before calling any other functions in this controller.     �    A value indicating whether an error occurred. A negative error code indicates function failure.

Error codes are defined in cvi\include\cvidotnet.h.

You can use CDotNetGetErrorDescription to get the description of an error code.    
�
���    �    Library Status                     	            j    Closes this CVI .NET controller.

Call this function after your program is done using this controller.     �    A value indicating whether an error occurred. A negative error code indicates function failure.

Error codes are defined in cvi\include\cvidotnet.h.

You can use CDotNetGetErrorDescription to get the description of an error code.    �
���    �    Library Status                     	            �    A value indicating whether an error occurred. A negative error code indicates function failure.

Error codes are defined in cvi\include\cvidotnet.h.

You can use CDotNetGetErrorDescription to get the description of an error code.        A handle to the exception thrown by the target .NET assembly. If the output value is not NULL, then you must discard it using CDotNetDiscardHandle. Call CDotNetGetExceptionInfo to get information about the exception.

You may pass NULL for this parameter.    �
���    �    Library Status                  ���� -       �    returnValue                       � - �   �    Exception Handle                   	            	            
        0    �    A value indicating whether an error occurred. A negative error code indicates function failure.

Error codes are defined in cvi\include\cvidotnet.h.

You can use CDotNetGetErrorDescription to get the description of an error code.        A handle to the exception thrown by the target .NET assembly. If the output value is not NULL, then you must discard it using CDotNetDiscardHandle. Call CDotNetGetExceptionInfo to get information about the exception.

You may pass NULL for this parameter.    �
���    �    Library Status                  ���� -   '  �    ir                              ���� - � ,  �    parent                          ���� -�     �    xsize                           ���� �      �    ysize                           ���� � �          resize                            w ��   �    Exception Handle                   	                            True 1 False 0    
        0    �    A value indicating whether an error occurred. A negative error code indicates function failure.

Error codes are defined in cvi\include\cvidotnet.h.

You can use CDotNetGetErrorDescription to get the description of an error code.        A handle to the exception thrown by the target .NET assembly. If the output value is not NULL, then you must discard it using CDotNetDiscardHandle. Call CDotNetGetExceptionInfo to get information about the exception.

You may pass NULL for this parameter.    0
���    �    Library Status                    # -     �    Exception Handle                   	            
        0 ����         
l  �             K.        Initialize_IRTrans_SendIR                                                                                                               ����           �             K.        Close_IRTrans_SendIR                                                                                                                    ����       ����  �             K.        IRTrans_SendIR_SendIR_SendIRVisible                                                                                                     ����       ����  �             K.        IRTrans_SendIR_SendIR_ShowSendIR                                                                                                        ����       ����  .             K.        IRTrans_SendIR_SendIR_SendIRDispose                                                                                                           �                                                                                     �Initialize                                                                           �Close                                                                             ����IRTrans_SendIR_SendIR                                                                �IRTrans SendIR SendIR SendIRVisible                                                  �IRTrans SendIR SendIR ShowSendIR                                                     �IRTrans SendIR SendIR SendIRDispose                                             