#include "nxc_f90.h"
extern "C"{

int nxc_f90_func_init_(double  pos[], int * nua, double  cell[], int  grid[], int isa[],
            char symbols[], int * ns, int * ierr, char  modelpath[], int * pathlen, int myBox[],
            int * edens, int * add, int * cuda){

    std::string modeldir(modelpath);
    modeldir = modeldir.erase(*pathlen, std::string::npos);
    func_param fp = {pos, *nua, cell, grid, isa, symbols, *ns, myBox, *edens, *add, *cuda};
    nxc_func_init(&nxc_func, modeldir, fp);

  return 0;
}

int nxc_f90_lda_exc_vxc_(int* np, double rho[], double exc [], double vrho[], int* ierr) {
  nxc_lda_exc_vxc(&nxc_func, *np, rho, exc, vrho);
  return 0;
}

int nxc_f90_lda_exc_vxc_fs_(int* np, double rho[], double exc[], double vrho[],
                            double forces[], double stress[], int* ierr) {
  nxc_lda_exc_vxc_fs(&nxc_func, *np, rho, exc, vrho, forces, stress);
  return 0;

}

int nxc_f90_gga_exc_vxc_(int* np, double rho[], double sigma[], double exc [],
    double vrho[], double vsigma[], int* ierr) {
  nxc_gga_exc_vxc(&nxc_func, *np, rho, sigma, exc, vrho, vsigma);
  return 0;
}

int nxc_f90_mgga_exc_vxc_(int* np, double rho[], double sigma[], double lapl[], double tau[],
   double exc [], double vrho[], double vsigma[], double vlapl[], double vtau[], int* ierr) {
  nxc_mgga_exc_vxc(&nxc_func, *np, rho, sigma, lapl, tau, exc, vrho, vsigma, vlapl, vtau);
  return 0;
}


}
