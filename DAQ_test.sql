-- phpMyAdmin SQL Dump
-- version 4.4.11
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Jul 20, 2015 at 05:40 AM
-- Server version: 5.5.32-MariaDB
-- PHP Version: 5.4.20

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `datalogger`
--

-- --------------------------------------------------------

--
-- Table structure for table `DAQ_test`
--

CREATE TABLE IF NOT EXISTS `DAQ_test` (
  `id_` int(11) NOT NULL COMMENT 'index register',
  `millisecond` bigint(20) NOT NULL,
  `rxtimestamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `ec` float NOT NULL,
  `ph` float DEFAULT NULL,
  `temperature` float NOT NULL,
  `humidity` float NOT NULL,
  `water_temperature` float NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=36 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `DAQ_test`
--

INSERT INTO `DAQ_test` (`id_`, `millisecond`, `rxtimestamp`, `ec`, `ph`, `temperature`, `humidity`, `water_temperature`) VALUES
(1, 11110236, '2015-07-20 05:39:05', 20, 30, 40, 50, 6),
(2, 11110236, '2015-07-20 05:39:05', 20, 30, 40, 50, 6),
(3, 11110236, '2015-07-20 05:39:05', 20, 30, 40, 50, 6),
(4, 11110236, '2015-07-20 05:39:05', 20, 30, 40, 50, 6),
(5, 11110236, '2015-07-20 05:39:05', 20, 30, 40, 50, 6),
(6, 11110236, '2015-07-20 05:39:05', 20, 30, 40, 50, 6),
(7, 11110236, '2015-07-20 05:39:05', 20, 30, 40, 50, 6),
(8, 11110236, '2015-07-20 05:39:05', 20, 30, 40, 50, 6),
(9, 11110236, '2015-07-20 05:39:05', 20, 30, 40, 50, 6),
(10, 11110236, '2015-07-20 05:39:05', 20, 30, 40, 50, 6),
(11, 11110236, '2015-07-20 05:39:05', 20, 30, 40, 50, 6),
(12, 11110236, '2015-07-20 05:39:06', 20, 30, 40, 50, 6),
(13, 11110236, '2015-07-20 05:39:06', 20, 30, 40, 50, 6),
(14, 11110236, '2015-07-20 05:39:06', 20, 30, 40, 50, 6),
(15, 11110236, '2015-07-20 05:39:06', 20, 30, 40, 50, 6),
(16, 11110236, '2015-07-20 05:39:06', 20, 30, 40, 50, 6),
(17, 11110236, '2015-07-20 05:39:06', 20, 30, 40, 50, 6),
(18, 11110236, '2015-07-20 05:39:06', 20, 30, 40, 50, 6),
(19, 11110236, '2015-07-20 05:39:06', 20, 30, 40, 50, 6),
(20, 11110236, '2015-07-20 05:39:06', 20, 30, 40, 50, 6),
(21, 11110236, '2015-07-20 05:39:06', 20, 30, 40, 50, 6),
(22, 11110236, '2015-07-20 05:39:06', 20, 30, 40, 50, 6),
(23, 11110236, '2015-07-20 05:39:06', 20, 30, 40, 50, 6),
(24, 11110236, '2015-07-20 05:39:06', 20, 30, 40, 50, 6),
(25, 11110236, '2015-07-20 05:39:06', 20, 30, 40, 50, 6),
(26, 11110236, '2015-07-20 05:39:06', 20, 30, 40, 50, 6),
(27, 11110236, '2015-07-20 05:39:06', 20, 30, 40, 50, 6),
(28, 11110236, '2015-07-20 05:39:06', 20, 30, 40, 50, 6),
(29, 11110236, '2015-07-20 05:39:06', 20, 30, 40, 50, 6),
(30, 11110236, '2015-07-20 05:39:06', 20, 30, 40, 50, 6),
(31, 11110236, '2015-07-20 05:39:06', 20, 30, 40, 50, 6),
(32, 11110236, '2015-07-20 05:39:07', 20, 30, 40, 50, 6),
(33, 11110236, '2015-07-20 05:39:07', 20, 30, 40, 50, 6),
(34, 11110236, '2015-07-20 05:39:07', 20, 30, 40, 50, 6),
(35, 11110236, '2015-07-20 05:39:07', 20, 30, 40, 50, 6);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `DAQ_test`
--
ALTER TABLE `DAQ_test`
  ADD PRIMARY KEY (`id_`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `DAQ_test`
--
ALTER TABLE `DAQ_test`
  MODIFY `id_` int(11) NOT NULL AUTO_INCREMENT COMMENT 'index register',AUTO_INCREMENT=36;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
