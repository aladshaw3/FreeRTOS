## Pytest for blinky demo

import pytest
import sys
from subprocess import run

# -----------------------------------------------------------------------------
# Start test for Blinky
class Test_Blinky:
    @pytest.fixture(scope="class")
    def case(self):
        run_cmd = ['./win_demo.exe']

        return run_cmd

    def test_run_exe(self, case):
        p = run(['make'])
        p = run(case)
        assert(p.returncode==0)
