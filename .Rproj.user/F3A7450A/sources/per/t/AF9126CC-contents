#' BLEST for Discrete Variables
#'
#' Computes the BLEST dependence measure for discrete random variables.
#'
#' @param support_x Vector of support values for X
#' @param support_y Vector of support values for Y
#' @param joint_pmf Function returning P(X=i, Y=j)
#' @param px Function returning P(X=i)
#' @param py Function returning P(Y=j)
#' @param Fx Function returning F_X(i)
#' @param Fy Function returning F_Y(j)
#'
#' @return Numeric value of BLEST
#' @export

blest <- function(
    support_x,
    support_y,
    joint_pmf,
    px,
    py,
    Fx,
    Fy
) {

  total_sum <- 0

  for (i in support_x) {
    for (j in support_y) {

      pij <- joint_pmf(i, j)
      pi  <- px(i)
      pj  <- py(j)
      U_im1 <- Fx(i-1)
      U_i   <- Fx(i)
      V_jm1 <- Fy(j - 1)
      V_j   <- Fy(j)

      term1 <- (1 - U_im1)^2 + (1 - U_i)^2+((1 - U_im1)* (1 - U_i))
      term2 <- V_j + V_jm1

      total_sum <- total_sum +
        (pij) * term1 * term2
    }
  }

  blest <- 2 - 2 * total_sum
  return(blest)
}

