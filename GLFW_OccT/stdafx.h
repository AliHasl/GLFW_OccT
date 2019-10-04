#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <iostream>

#pragma warning (  disable : 4244 )        // Issue warning 4244
#include "Standard_ShortReal.hxx"
#pragma warning (  default : 4244 )        // Issue warning 4244
#include <Standard.hxx>
#include <Standard_PrimitiveTypes.hxx>
#include <Standard_Real.hxx>
#include <AIS_InteractiveContext.hxx>
#include <AIS_Line.hxx>
#include <AIS_Shape.hxx>
//#include <AIS_Drawer.hxx>
#include <AIS_Point.hxx>
#include <AIS_TexturedShape.hxx>
#include <Aspect_Grid.hxx>
#include <Aspect_PolygonOffsetMode.hxx>
//#include <Aspect_TypeOfText.hxx>
#include <Aspect_DisplayConnection.hxx>
//#include <Aspect_AspectMarker.hxx>

#include <BRep_Tool.hxx>
#include <BRepTools.hxx>
#include <BRepBuilderAPI_NurbsConvert.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBndLib.hxx>
#include <BRepAdaptor_HArray1OfCurve.hxx>
#include <BRepAdaptor_Curve2d.hxx>
#include <BRepBuilderAPI_MakeVertex.hxx>
#include <Geom_BezierCurve.hxx>
#include <BRepFeat_MakePipe.hxx>
#include <BRepOffsetAPI_MakePipe.hxx>

#include <GCPnts_QuasiUniformDeflection.hxx>

#include <Geom2d_TrimmedCurve.hxx>
#include <GeomLib.hxx>
#include <Geom_Surface.hxx>
#include <Geom_Curve.hxx>
#include <Geom_Plane.hxx>
#include <Geom_CartesianPoint.hxx>
#include <GeomAPI_Interpolate.hxx>

#include <Graphic3d_Group.hxx>
#include <Graphic3d_HorizontalTextAlignment.hxx>
#include <Graphic3d_VerticalTextAlignment.hxx>
//#include <Graphic3d_Array1OfVertex.hxx>
#include <Graphic3d_ArrayOfPolylines.hxx>
//#include <Graphic3d.hxx>
//#include <OpenGl_GraphicDriver.hxx>		//Replace Graphic3d.hxx by OpenGl_GraphicDriver.hxx
#include <Graphic3d_GraphicDriver.hxx>
#include <Graphic3d_ExportFormat.hxx>
#include <Graphic3d_ArrayOfPolylines.hxx>
#include <Graphic3d_AspectFillArea3d.hxx>
#include <Graphic3d_AspectText3d.hxx>
#include <Graphic3d_AspectLine3d.hxx>
#include <Graphic3d_AspectMarker3d.hxx>
#include <Graphic3d_Texture1Dsegment.hxx>

#include <gp_Pln.hxx>
#include <gp.hxx>
#include <gp_Pnt2d.hxx>

#include <Prs3d_Root.hxx>
#include <Prs3d_Drawer.hxx>
#include <Prs3d_IsoAspect.hxx>
#include <Prs3d_ShadingAspect.hxx>
#include <Prs3d_Presentation.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_TextAspect.hxx>
#include <Prs3d_Text.hxx>
#include <Select3D_SensitiveBox.hxx>
#include <Select3D_SensitiveCurve.hxx>
#include <Select3D_SensitiveGroup.hxx>
#include <SelectMgr_Selection.hxx>
#include <SelectMgr_SequenceOfOwner.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <ShapeBuild_Edge.hxx>
#include <StdSelect_ViewerSelector3d.hxx>
#include <StdPrs_ShadedShape.hxx>
#include <StdPrs_HLRPolyShape.hxx>
#include <StdSelect_BRepSelectionTool.hxx>
#include <StdPrs_WFShape.hxx>
#include <StdPrs_ToolRFace.hxx>
#include <StdSelect.hxx>
#include <StdSelect_BRepOwner.hxx>
#include <StdSelect_BRepSelectionTool.hxx>
#include <TCollection_AsciiString.hxx>
#include "TopExp.hxx"
#include <TopExp_Explorer.hxx>

#include <TopoDS.hxx>
#include <TopoDS_Builder.hxx>
#include <TopoDS_Compound.hxx>
#include <TopoDS_ListOfShape.hxx>
#include <TopoDS_ListIteratorOfListOfShape.hxx>
#include <TopoDS_Iterator.hxx>
#include "TopoDS_Edge.hxx"
#include "TopoDS_Vertex.hxx"
#include <TopTools_HSequenceOfShape.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <Graphic3d_CView.hxx>
#include <V3d_Viewer.hxx>
#include <V3d_View.hxx>
#include <WNT_Window.hxx>
#include <Xw_Window.hxx>
#include <Standard_Macro.hxx>
#include <Graphic3d_GraphicDriver.hxx>
#include <Standard_Failure.hxx>

#include <BRepAlgoAPI_Fuse.hxx>
#include <BRepAlgoAPI_Common.hxx>
#include <BRepAlgoAPI_Cut.hxx>
#include <BRepBuilderAPI_Transform.hxx>
#include <BRepFilletAPI_MakeFillet.hxx>
#include <BRepLib.hxx>
#include <BRepOffsetAPI_MakeThickSolid.hxx>
#include <BRepOffsetAPI_ThruSections.hxx>
#include <BRepOffsetAPI_MakePipeShell.hxx>
#include <BRepOffsetAPI_MakePipe.hxx>
#include <BRepPrimAPI_MakePrism.hxx>

#include <GC_MakeArcOfCircle.hxx>
#include <GC_MakeSegment.hxx>
#include <GC_MakeCircle.hxx>
#include <GCE2d_MakeSegment.hxx>



#include <gp_Ax1.hxx>
#include <gp_Ax2.hxx>
#include <gp_Ax2d.hxx>
#include <gp_Dir.hxx>
#include <gp_Dir2d.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Trsf.hxx>
#include <gp_Vec.hxx>

#include <Geom_CylindricalSurface.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Geom2d_Ellipse.hxx>
#include <GeomAPI_PointsToBSpline.hxx>

#include <TopoDS_Face.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Shape.hxx>
#include <V3d_BadValue.hxx>

#include <AIS_InteractiveObject.hxx>
#include <AIS_ListOfInteractive.hxx>
#include <AIS_LocalContext.hxx>
#include <SelectMgr_EntityOwner.hxx>

#include <ShapeFix.hxx>
#include <ShapeFix_Wire.hxx>
#include <math.h>
#include <math.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopTools_ListIteratorOfListOfShape.hxx>