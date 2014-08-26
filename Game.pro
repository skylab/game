TEMPLATE = app
#CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG+=c++11

LIBS += -lGLEW -lglut -lGL

SOURCES += main.cpp \
    GraphicSystem/graphicsystem.cpp \
    game.cpp \
    GraphicSystem/Scenes/sceneabs.cpp \
    GraphicSystem/Objects/objectabs.cpp \
    GraphicSystem/Shaders/shader.cpp \
    GraphicSystem/Shaders/shaderprogram.cpp \
    GraphicSystem/Objects/objecttriangle.cpp \
    GraphicSystem/Objects/objectcube.cpp \
    GraphicSystem/Objects/objectquad.cpp \
    GraphicSystem/Scenes/menuscene.cpp \
    GraphicSystem/Scenes/gamescene.cpp \
    PhysicSystem/BulletDynamics/ConstraintSolver/btConeTwistConstraint.cpp \
    PhysicSystem/BulletDynamics/ConstraintSolver/btContactConstraint.cpp \
    PhysicSystem/BulletDynamics/ConstraintSolver/btFixedConstraint.cpp \
    PhysicSystem/BulletDynamics/ConstraintSolver/btGearConstraint.cpp \
    PhysicSystem/BulletDynamics/ConstraintSolver/btGeneric6DofConstraint.cpp \
    PhysicSystem/BulletDynamics/ConstraintSolver/btGeneric6DofSpringConstraint.cpp \
    PhysicSystem/BulletDynamics/ConstraintSolver/btHinge2Constraint.cpp \
    PhysicSystem/BulletDynamics/ConstraintSolver/btHingeConstraint.cpp \
    PhysicSystem/BulletDynamics/ConstraintSolver/btPoint2PointConstraint.cpp \
    PhysicSystem/BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.cpp \
    PhysicSystem/BulletDynamics/ConstraintSolver/btSliderConstraint.cpp \
    PhysicSystem/BulletDynamics/ConstraintSolver/btSolve2LinearConstraint.cpp \
    PhysicSystem/BulletDynamics/ConstraintSolver/btTypedConstraint.cpp \
    PhysicSystem/BulletDynamics/ConstraintSolver/btUniversalConstraint.cpp \
    PhysicSystem/BulletDynamics/Dynamics/btDiscreteDynamicsWorld.cpp \
    PhysicSystem/BulletDynamics/Dynamics/btRigidBody.cpp \
    PhysicSystem/BulletDynamics/Dynamics/btSimpleDynamicsWorld.cpp \
    PhysicSystem/BulletDynamics/Dynamics/Bullet-C-API.cpp \
    PhysicSystem/BulletDynamics/Vehicle/btRaycastVehicle.cpp \
    PhysicSystem/BulletDynamics/Vehicle/btWheelInfo.cpp \
    PhysicSystem/LinearMath/btAlignedAllocator.cpp \
    PhysicSystem/LinearMath/btConvexHull.cpp \
    PhysicSystem/LinearMath/btConvexHullComputer.cpp \
    PhysicSystem/LinearMath/btGeometryUtil.cpp \
    PhysicSystem/LinearMath/btPolarDecomposition.cpp \
    PhysicSystem/LinearMath/btQuickprof.cpp \
    PhysicSystem/LinearMath/btSerializer.cpp \
    PhysicSystem/LinearMath/btVector3.cpp \
    PhysicSystem/BulletCollision/BroadphaseCollision/btAxisSweep3.cpp \
    PhysicSystem/BulletCollision/BroadphaseCollision/btBroadphaseProxy.cpp \
    PhysicSystem/BulletCollision/BroadphaseCollision/btCollisionAlgorithm.cpp \
    PhysicSystem/BulletCollision/BroadphaseCollision/btDbvt.cpp \
    PhysicSystem/BulletCollision/BroadphaseCollision/btDbvtBroadphase.cpp \
    PhysicSystem/BulletCollision/BroadphaseCollision/btDispatcher.cpp \
    PhysicSystem/BulletCollision/BroadphaseCollision/btMultiSapBroadphase.cpp \
    PhysicSystem/BulletCollision/BroadphaseCollision/btOverlappingPairCache.cpp \
    PhysicSystem/BulletCollision/BroadphaseCollision/btQuantizedBvh.cpp \
    PhysicSystem/BulletCollision/BroadphaseCollision/btSimpleBroadphase.cpp \
    PhysicSystem/BulletCollision/CollisionDispatch/btActivatingCollisionAlgorithm.cpp \
    PhysicSystem/BulletCollision/CollisionDispatch/btBox2dBox2dCollisionAlgorithm.cpp \
    PhysicSystem/BulletCollision/CollisionDispatch/btBoxBoxCollisionAlgorithm.cpp \
    PhysicSystem/BulletCollision/CollisionDispatch/btBoxBoxDetector.cpp \
    PhysicSystem/BulletCollision/CollisionDispatch/btCollisionDispatcher.cpp \
    PhysicSystem/BulletCollision/CollisionDispatch/btCollisionObject.cpp \
    PhysicSystem/BulletCollision/CollisionDispatch/btCollisionWorld.cpp \
    PhysicSystem/BulletCollision/CollisionDispatch/btCompoundCollisionAlgorithm.cpp \
    PhysicSystem/BulletCollision/CollisionDispatch/btCompoundCompoundCollisionAlgorithm.cpp \
    PhysicSystem/BulletCollision/CollisionDispatch/btConvex2dConvex2dAlgorithm.cpp \
    PhysicSystem/BulletCollision/CollisionDispatch/btConvexConcaveCollisionAlgorithm.cpp \
    PhysicSystem/BulletCollision/CollisionDispatch/btConvexConvexAlgorithm.cpp \
    PhysicSystem/BulletCollision/CollisionDispatch/btConvexPlaneCollisionAlgorithm.cpp \
    PhysicSystem/BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.cpp \
    PhysicSystem/BulletCollision/CollisionDispatch/btEmptyCollisionAlgorithm.cpp \
    PhysicSystem/BulletCollision/CollisionDispatch/btGhostObject.cpp \
    PhysicSystem/BulletCollision/CollisionDispatch/btHashedSimplePairCache.cpp \
    PhysicSystem/BulletCollision/CollisionDispatch/btInternalEdgeUtility.cpp \
    PhysicSystem/BulletCollision/CollisionDispatch/btManifoldResult.cpp \
    PhysicSystem/BulletCollision/CollisionDispatch/btSimulationIslandManager.cpp \
    PhysicSystem/BulletCollision/CollisionDispatch/btSphereBoxCollisionAlgorithm.cpp \
    PhysicSystem/BulletCollision/CollisionDispatch/btSphereSphereCollisionAlgorithm.cpp \
    PhysicSystem/BulletCollision/CollisionDispatch/btSphereTriangleCollisionAlgorithm.cpp \
    PhysicSystem/BulletCollision/CollisionDispatch/btUnionFind.cpp \
    PhysicSystem/BulletCollision/CollisionDispatch/SphereTriangleDetector.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btBox2dShape.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btBoxShape.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btBvhTriangleMeshShape.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btCapsuleShape.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btCollisionShape.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btCompoundShape.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btConcaveShape.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btConeShape.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btConvex2dShape.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btConvexHullShape.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btConvexInternalShape.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btConvexPointCloudShape.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btConvexPolyhedron.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btConvexShape.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btConvexTriangleMeshShape.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btCylinderShape.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btEmptyShape.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btHeightfieldTerrainShape.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btMinkowskiSumShape.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btMultimaterialTriangleMeshShape.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btMultiSphereShape.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btOptimizedBvh.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btPolyhedralConvexShape.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btScaledBvhTriangleMeshShape.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btShapeHull.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btSphereShape.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btStaticPlaneShape.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btStridingMeshInterface.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btTetrahedronShape.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btTriangleBuffer.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btTriangleCallback.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btTriangleIndexVertexArray.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btTriangleIndexVertexMaterialArray.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btTriangleMesh.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btTriangleMeshShape.cpp \
    PhysicSystem/BulletCollision/CollisionShapes/btUniformScalingShape.cpp \
    PhysicSystem/BulletCollision/Gimpact/btContactProcessing.cpp \
    PhysicSystem/BulletCollision/Gimpact/btGenericPoolAllocator.cpp \
    PhysicSystem/BulletCollision/Gimpact/btGImpactBvh.cpp \
    PhysicSystem/BulletCollision/Gimpact/btGImpactCollisionAlgorithm.cpp \
    PhysicSystem/BulletCollision/Gimpact/btGImpactQuantizedBvh.cpp \
    PhysicSystem/BulletCollision/Gimpact/btGImpactShape.cpp \
    PhysicSystem/BulletCollision/Gimpact/btTriangleShapeEx.cpp \
    PhysicSystem/BulletCollision/Gimpact/gim_box_set.cpp \
    PhysicSystem/BulletCollision/Gimpact/gim_contact.cpp \
    PhysicSystem/BulletCollision/Gimpact/gim_memory.cpp \
    PhysicSystem/BulletCollision/Gimpact/gim_tri_collision.cpp \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btContinuousConvexCollision.cpp \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btConvexCast.cpp \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btGjkConvexCast.cpp \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btGjkEpa2.cpp \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btGjkEpaPenetrationDepthSolver.cpp \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btGjkPairDetector.cpp \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btMinkowskiPenetrationDepthSolver.cpp \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btPersistentManifold.cpp \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btPolyhedralContactClipping.cpp \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btRaycastCallback.cpp \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btSubSimplexConvexCast.cpp \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btVoronoiSimplexSolver.cpp \
    PhysicSystem/BulletDynamics/Character/btKinematicCharacterController.cpp \
    PhysicSystem/BulletDynamics/Featherstone/btMultiBody.cpp \
    PhysicSystem/BulletDynamics/Featherstone/btMultiBodyConstraint.cpp \
    PhysicSystem/BulletDynamics/Featherstone/btMultiBodyConstraintSolver.cpp \
    PhysicSystem/BulletDynamics/Featherstone/btMultiBodyDynamicsWorld.cpp \
    PhysicSystem/BulletDynamics/Featherstone/btMultiBodyJointLimitConstraint.cpp \
    PhysicSystem/BulletDynamics/Featherstone/btMultiBodyJointMotor.cpp \
    PhysicSystem/BulletDynamics/Featherstone/btMultiBodyPoint2Point.cpp \
    PhysicSystem/BulletDynamics/MLCPSolvers/btDantzigLCP.cpp \
    PhysicSystem/BulletDynamics/MLCPSolvers/btMLCPSolver.cpp \
    PhysicSystem/physicsystem.cpp

HEADERS += \
    GraphicSystem/graphicsystem.h \
    game.h \
    GraphicSystem/pregraphic.h \
    GraphicSystem/Scenes/sceneabs.h \
    GraphicSystem/Objects/objectabs.h \
    GraphicSystem/Shaders/shader.h \
    GraphicSystem/Shaders/shaderprogram.h \
    GraphicSystem/Objects/objecttriangle.h \
    GraphicSystem/Objects/objectcube.h \
    GraphicSystem/Objects/objectquad.h \
    GraphicSystem/Scenes/menuscene.h \
    GraphicSystem/Scenes/gamescene.h \
    PhysicSystem/btBulletDynamicsCommon.h \
    PhysicSystem/btBulletCollisionCommon.h \
    PhysicSystem/BulletDynamics/ConstraintSolver/btConeTwistConstraint.h \
    PhysicSystem/BulletDynamics/ConstraintSolver/btConstraintSolver.h \
    PhysicSystem/BulletDynamics/ConstraintSolver/btContactConstraint.h \
    PhysicSystem/BulletDynamics/ConstraintSolver/btContactSolverInfo.h \
    PhysicSystem/BulletDynamics/ConstraintSolver/btFixedConstraint.h \
    PhysicSystem/BulletDynamics/ConstraintSolver/btGearConstraint.h \
    PhysicSystem/BulletDynamics/ConstraintSolver/btGeneric6DofConstraint.h \
    PhysicSystem/BulletDynamics/ConstraintSolver/btGeneric6DofSpringConstraint.h \
    PhysicSystem/BulletDynamics/ConstraintSolver/btHinge2Constraint.h \
    PhysicSystem/BulletDynamics/ConstraintSolver/btHingeConstraint.h \
    PhysicSystem/BulletDynamics/ConstraintSolver/btJacobianEntry.h \
    PhysicSystem/BulletDynamics/ConstraintSolver/btPoint2PointConstraint.h \
    PhysicSystem/BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.h \
    PhysicSystem/BulletDynamics/ConstraintSolver/btSliderConstraint.h \
    PhysicSystem/BulletDynamics/ConstraintSolver/btSolve2LinearConstraint.h \
    PhysicSystem/BulletDynamics/ConstraintSolver/btSolverBody.h \
    PhysicSystem/BulletDynamics/ConstraintSolver/btSolverConstraint.h \
    PhysicSystem/BulletDynamics/ConstraintSolver/btTypedConstraint.h \
    PhysicSystem/BulletDynamics/ConstraintSolver/btUniversalConstraint.h \
    PhysicSystem/BulletDynamics/Dynamics/btActionInterface.h \
    PhysicSystem/BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h \
    PhysicSystem/BulletDynamics/Dynamics/btDynamicsWorld.h \
    PhysicSystem/BulletDynamics/Dynamics/btRigidBody.h \
    PhysicSystem/BulletDynamics/Dynamics/btSimpleDynamicsWorld.h \
    PhysicSystem/BulletDynamics/Vehicle/btRaycastVehicle.h \
    PhysicSystem/BulletDynamics/Vehicle/btVehicleRaycaster.h \
    PhysicSystem/BulletDynamics/Vehicle/btWheelInfo.h \
    PhysicSystem/LinearMath/btAabbUtil2.h \
    PhysicSystem/LinearMath/btAlignedAllocator.h \
    PhysicSystem/LinearMath/btAlignedObjectArray.h \
    PhysicSystem/LinearMath/btConvexHull.h \
    PhysicSystem/LinearMath/btConvexHullComputer.h \
    PhysicSystem/LinearMath/btDefaultMotionState.h \
    PhysicSystem/LinearMath/btGeometryUtil.h \
    PhysicSystem/LinearMath/btGrahamScan2dConvexHull.h \
    PhysicSystem/LinearMath/btHashMap.h \
    PhysicSystem/LinearMath/btIDebugDraw.h \
    PhysicSystem/LinearMath/btList.h \
    PhysicSystem/LinearMath/btMatrix3x3.h \
    PhysicSystem/LinearMath/btMatrixX.h \
    PhysicSystem/LinearMath/btMinMax.h \
    PhysicSystem/LinearMath/btMotionState.h \
    PhysicSystem/LinearMath/btPolarDecomposition.h \
    PhysicSystem/LinearMath/btPoolAllocator.h \
    PhysicSystem/LinearMath/btQuadWord.h \
    PhysicSystem/LinearMath/btQuaternion.h \
    PhysicSystem/LinearMath/btQuickprof.h \
    PhysicSystem/LinearMath/btRandom.h \
    PhysicSystem/LinearMath/btScalar.h \
    PhysicSystem/LinearMath/btSerializer.h \
    PhysicSystem/LinearMath/btStackAlloc.h \
    PhysicSystem/LinearMath/btTransform.h \
    PhysicSystem/LinearMath/btTransformUtil.h \
    PhysicSystem/LinearMath/btVector3.h \
    PhysicSystem/BulletCollision/BroadphaseCollision/btAxisSweep3.h \
    PhysicSystem/BulletCollision/BroadphaseCollision/btBroadphaseInterface.h \
    PhysicSystem/BulletCollision/BroadphaseCollision/btBroadphaseProxy.h \
    PhysicSystem/BulletCollision/BroadphaseCollision/btCollisionAlgorithm.h \
    PhysicSystem/BulletCollision/BroadphaseCollision/btDbvt.h \
    PhysicSystem/BulletCollision/BroadphaseCollision/btDbvtBroadphase.h \
    PhysicSystem/BulletCollision/BroadphaseCollision/btDispatcher.h \
    PhysicSystem/BulletCollision/BroadphaseCollision/btMultiSapBroadphase.h \
    PhysicSystem/BulletCollision/BroadphaseCollision/btOverlappingPairCache.h \
    PhysicSystem/BulletCollision/BroadphaseCollision/btOverlappingPairCallback.h \
    PhysicSystem/BulletCollision/BroadphaseCollision/btQuantizedBvh.h \
    PhysicSystem/BulletCollision/BroadphaseCollision/btSimpleBroadphase.h \
    PhysicSystem/BulletCollision/CollisionDispatch/btActivatingCollisionAlgorithm.h \
    PhysicSystem/BulletCollision/CollisionDispatch/btBox2dBox2dCollisionAlgorithm.h \
    PhysicSystem/BulletCollision/CollisionDispatch/btBoxBoxCollisionAlgorithm.h \
    PhysicSystem/BulletCollision/CollisionDispatch/btBoxBoxDetector.h \
    PhysicSystem/BulletCollision/CollisionDispatch/btCollisionConfiguration.h \
    PhysicSystem/BulletCollision/CollisionDispatch/btCollisionCreateFunc.h \
    PhysicSystem/BulletCollision/CollisionDispatch/btCollisionDispatcher.h \
    PhysicSystem/BulletCollision/CollisionDispatch/btCollisionObject.h \
    PhysicSystem/BulletCollision/CollisionDispatch/btCollisionObjectWrapper.h \
    PhysicSystem/BulletCollision/CollisionDispatch/btCollisionWorld.h \
    PhysicSystem/BulletCollision/CollisionDispatch/btCompoundCollisionAlgorithm.h \
    PhysicSystem/BulletCollision/CollisionDispatch/btCompoundCompoundCollisionAlgorithm.h \
    PhysicSystem/BulletCollision/CollisionDispatch/btConvex2dConvex2dAlgorithm.h \
    PhysicSystem/BulletCollision/CollisionDispatch/btConvexConcaveCollisionAlgorithm.h \
    PhysicSystem/BulletCollision/CollisionDispatch/btConvexConvexAlgorithm.h \
    PhysicSystem/BulletCollision/CollisionDispatch/btConvexPlaneCollisionAlgorithm.h \
    PhysicSystem/BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.h \
    PhysicSystem/BulletCollision/CollisionDispatch/btEmptyCollisionAlgorithm.h \
    PhysicSystem/BulletCollision/CollisionDispatch/btGhostObject.h \
    PhysicSystem/BulletCollision/CollisionDispatch/btHashedSimplePairCache.h \
    PhysicSystem/BulletCollision/CollisionDispatch/btInternalEdgeUtility.h \
    PhysicSystem/BulletCollision/CollisionDispatch/btManifoldResult.h \
    PhysicSystem/BulletCollision/CollisionDispatch/btSimulationIslandManager.h \
    PhysicSystem/BulletCollision/CollisionDispatch/btSphereBoxCollisionAlgorithm.h \
    PhysicSystem/BulletCollision/CollisionDispatch/btSphereSphereCollisionAlgorithm.h \
    PhysicSystem/BulletCollision/CollisionDispatch/btSphereTriangleCollisionAlgorithm.h \
    PhysicSystem/BulletCollision/CollisionDispatch/btUnionFind.h \
    PhysicSystem/BulletCollision/CollisionDispatch/SphereTriangleDetector.h \
    PhysicSystem/BulletCollision/CollisionShapes/btBox2dShape.h \
    PhysicSystem/BulletCollision/CollisionShapes/btBoxShape.h \
    PhysicSystem/BulletCollision/CollisionShapes/btBvhTriangleMeshShape.h \
    PhysicSystem/BulletCollision/CollisionShapes/btCapsuleShape.h \
    PhysicSystem/BulletCollision/CollisionShapes/btCollisionMargin.h \
    PhysicSystem/BulletCollision/CollisionShapes/btCollisionShape.h \
    PhysicSystem/BulletCollision/CollisionShapes/btCompoundShape.h \
    PhysicSystem/BulletCollision/CollisionShapes/btConcaveShape.h \
    PhysicSystem/BulletCollision/CollisionShapes/btConeShape.h \
    PhysicSystem/BulletCollision/CollisionShapes/btConvex2dShape.h \
    PhysicSystem/BulletCollision/CollisionShapes/btConvexHullShape.h \
    PhysicSystem/BulletCollision/CollisionShapes/btConvexInternalShape.h \
    PhysicSystem/BulletCollision/CollisionShapes/btConvexPointCloudShape.h \
    PhysicSystem/BulletCollision/CollisionShapes/btConvexPolyhedron.h \
    PhysicSystem/BulletCollision/CollisionShapes/btConvexShape.h \
    PhysicSystem/BulletCollision/CollisionShapes/btConvexTriangleMeshShape.h \
    PhysicSystem/BulletCollision/CollisionShapes/btCylinderShape.h \
    PhysicSystem/BulletCollision/CollisionShapes/btEmptyShape.h \
    PhysicSystem/BulletCollision/CollisionShapes/btHeightfieldTerrainShape.h \
    PhysicSystem/BulletCollision/CollisionShapes/btMaterial.h \
    PhysicSystem/BulletCollision/CollisionShapes/btMinkowskiSumShape.h \
    PhysicSystem/BulletCollision/CollisionShapes/btMultimaterialTriangleMeshShape.h \
    PhysicSystem/BulletCollision/CollisionShapes/btMultiSphereShape.h \
    PhysicSystem/BulletCollision/CollisionShapes/btOptimizedBvh.h \
    PhysicSystem/BulletCollision/CollisionShapes/btPolyhedralConvexShape.h \
    PhysicSystem/BulletCollision/CollisionShapes/btScaledBvhTriangleMeshShape.h \
    PhysicSystem/BulletCollision/CollisionShapes/btShapeHull.h \
    PhysicSystem/BulletCollision/CollisionShapes/btSphereShape.h \
    PhysicSystem/BulletCollision/CollisionShapes/btStaticPlaneShape.h \
    PhysicSystem/BulletCollision/CollisionShapes/btStridingMeshInterface.h \
    PhysicSystem/BulletCollision/CollisionShapes/btTetrahedronShape.h \
    PhysicSystem/BulletCollision/CollisionShapes/btTriangleBuffer.h \
    PhysicSystem/BulletCollision/CollisionShapes/btTriangleCallback.h \
    PhysicSystem/BulletCollision/CollisionShapes/btTriangleIndexVertexArray.h \
    PhysicSystem/BulletCollision/CollisionShapes/btTriangleIndexVertexMaterialArray.h \
    PhysicSystem/BulletCollision/CollisionShapes/btTriangleInfoMap.h \
    PhysicSystem/BulletCollision/CollisionShapes/btTriangleMesh.h \
    PhysicSystem/BulletCollision/CollisionShapes/btTriangleMeshShape.h \
    PhysicSystem/BulletCollision/CollisionShapes/btTriangleShape.h \
    PhysicSystem/BulletCollision/CollisionShapes/btUniformScalingShape.h \
    PhysicSystem/BulletCollision/Gimpact/btBoxCollision.h \
    PhysicSystem/BulletCollision/Gimpact/btClipPolygon.h \
    PhysicSystem/BulletCollision/Gimpact/btCompoundFromGimpact.h \
    PhysicSystem/BulletCollision/Gimpact/btContactProcessing.h \
    PhysicSystem/BulletCollision/Gimpact/btGenericPoolAllocator.h \
    PhysicSystem/BulletCollision/Gimpact/btGeometryOperations.h \
    PhysicSystem/BulletCollision/Gimpact/btGImpactBvh.h \
    PhysicSystem/BulletCollision/Gimpact/btGImpactCollisionAlgorithm.h \
    PhysicSystem/BulletCollision/Gimpact/btGImpactMassUtil.h \
    PhysicSystem/BulletCollision/Gimpact/btGImpactQuantizedBvh.h \
    PhysicSystem/BulletCollision/Gimpact/btGImpactShape.h \
    PhysicSystem/BulletCollision/Gimpact/btQuantization.h \
    PhysicSystem/BulletCollision/Gimpact/btTriangleShapeEx.h \
    PhysicSystem/BulletCollision/Gimpact/gim_array.h \
    PhysicSystem/BulletCollision/Gimpact/gim_basic_geometry_operations.h \
    PhysicSystem/BulletCollision/Gimpact/gim_bitset.h \
    PhysicSystem/BulletCollision/Gimpact/gim_box_collision.h \
    PhysicSystem/BulletCollision/Gimpact/gim_box_set.h \
    PhysicSystem/BulletCollision/Gimpact/gim_clip_polygon.h \
    PhysicSystem/BulletCollision/Gimpact/gim_contact.h \
    PhysicSystem/BulletCollision/Gimpact/gim_geometry.h \
    PhysicSystem/BulletCollision/Gimpact/gim_geom_types.h \
    PhysicSystem/BulletCollision/Gimpact/gim_hash_table.h \
    PhysicSystem/BulletCollision/Gimpact/gim_linear_math.h \
    PhysicSystem/BulletCollision/Gimpact/gim_math.h \
    PhysicSystem/BulletCollision/Gimpact/gim_memory.h \
    PhysicSystem/BulletCollision/Gimpact/gim_radixsort.h \
    PhysicSystem/BulletCollision/Gimpact/gim_tri_collision.h \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btContinuousConvexCollision.h \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btConvexCast.h \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btConvexPenetrationDepthSolver.h \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btDiscreteCollisionDetectorInterface.h \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btGjkConvexCast.h \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btGjkEpa2.h \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btGjkEpaPenetrationDepthSolver.h \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btGjkPairDetector.h \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btManifoldPoint.h \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btMinkowskiPenetrationDepthSolver.h \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btPersistentManifold.h \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btPointCollector.h \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btPolyhedralContactClipping.h \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btRaycastCallback.h \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btSimplexSolverInterface.h \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btSubSimplexConvexCast.h \
    PhysicSystem/BulletCollision/NarrowPhaseCollision/btVoronoiSimplexSolver.h \
    PhysicSystem/BulletDynamics/Character/btCharacterControllerInterface.h \
    PhysicSystem/BulletDynamics/Character/btKinematicCharacterController.h \
    PhysicSystem/BulletDynamics/Featherstone/btMultiBody.h \
    PhysicSystem/BulletDynamics/Featherstone/btMultiBodyConstraint.h \
    PhysicSystem/BulletDynamics/Featherstone/btMultiBodyConstraintSolver.h \
    PhysicSystem/BulletDynamics/Featherstone/btMultiBodyDynamicsWorld.h \
    PhysicSystem/BulletDynamics/Featherstone/btMultiBodyJointLimitConstraint.h \
    PhysicSystem/BulletDynamics/Featherstone/btMultiBodyJointMotor.h \
    PhysicSystem/BulletDynamics/Featherstone/btMultiBodyLink.h \
    PhysicSystem/BulletDynamics/Featherstone/btMultiBodyLinkCollider.h \
    PhysicSystem/BulletDynamics/Featherstone/btMultiBodyPoint2Point.h \
    PhysicSystem/BulletDynamics/Featherstone/btMultiBodySolverConstraint.h \
    PhysicSystem/BulletDynamics/MLCPSolvers/btDantzigLCP.h \
    PhysicSystem/BulletDynamics/MLCPSolvers/btDantzigSolver.h \
    PhysicSystem/BulletDynamics/MLCPSolvers/btMLCPSolver.h \
    PhysicSystem/BulletDynamics/MLCPSolvers/btMLCPSolverInterface.h \
    PhysicSystem/BulletDynamics/MLCPSolvers/btPATHSolver.h \
    PhysicSystem/BulletDynamics/MLCPSolvers/btSolveProjectedGaussSeidel.h \
    PhysicSystem/physicsystem.h

OTHER_FILES += \
    GraphicSystem/Shaders/VertexShader.vsh \
    GraphicSystem/Shaders/FragmentShader.fsh

