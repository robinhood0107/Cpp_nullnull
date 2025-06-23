


int main() {
    {
        Monitor monitor;
        monitor.print();
    }
    stdcout  --------------------------  stdendl;
    {
        Monitor pMonitor = new LED_Monitor();
        if (pMonitor) delete pMonitor;
    }
    stdcout  --------------------------  stdendl;
    {
        stdunique_ptrOutputDevice pMonitor = stdmake_uniqueLCD_Monitor();
    }
}
