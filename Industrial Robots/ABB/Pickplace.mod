MODULE Module1
    !CONST robtarget Home:=[[0,0,0],[0,1,0,0],[0,0,0,0],[9E+09,9E+09,9E+09,9E+09,9E+09,9E+09]];
    CONST robtarget Target_10:=[[899.608,46.323,754],[0,1,0,0],[0,0,-2,0],[9E+09,9E+09,9E+09,9E+09,9E+09,9E+09]];
    CONST robtarget Target_10_up:=[[899.608,46.323,810],[0,1,0,0],[0,0,-2,0],[9E+09,9E+09,9E+09,9E+09,9E+09,9E+09]];
    CONST robtarget Target_20_up:=[[517.88,-771.683,885],[0,1,0,0],[-1,0,-3,0],[9E+09,9E+09,9E+09,9E+09,9E+09,9E+09]];
    CONST robtarget Target_20:=[[517.88,-771.683,785],[0,1,0,0],[-1,0,-3,0],[9E+09,9E+09,9E+09,9E+09,9E+09,9E+09]];
    VAR num a;
    CONST robtarget Home:=[[930.561516283,47.146966956,1185.237699066],[0.004439845,0.999309748,0.036457329,0.005583685],[0,-1,-3,0],[9E+09,9E+09,9E+09,9E+09,9E+09,9E+09]];
!***********************************************************
    
    PROC mainhere()
    MoveL Home,v1000,z100,tool0\WObj:=wobj0;    
    a:=5;
    Path_10;
    Path_10;        
        

    ENDPROC
    
    PROC Path_10()
        a:=.5;
        SetDO vacuum,0;
        SetDO vacuumoff,0;
        SetDO Position,1;
        MoveL Home,v1000,z100,tool0\WObj:=wobj0;
        !SetDO vacuumoff,1;
        MoveJ Target_10,v1000,z100,tool0\WObj:=wobj0;
        WaitTime\InPos,a;
        SetDO vacuum,high;
        MoveJ Target_10_up,v1000,z100,tool0\WObj:=wobj0;
        MoveJ Target_20_up,v1000,z100,tool0\WObj:=wobj0;
        MoveJ Target_20,v1000,z100,tool0\WObj:=wobj0;
        SetDO vacuum,0;
        WaitTime\InPos,a;
        SetDO vacuumoff,1;
        MoveJ Target_20_up,v1000,z100,tool0\WObj:=wobj0;
        MoveJ Target_10_up,v1000,z100,tool0\WObj:=wobj0;
        MoveL Home,v1000,z100,tool0\WObj:=wobj0;
    ENDPROC
    
ENDMODULE